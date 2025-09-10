import json, requests, re, html
from typing import TypedDict
from pathlib import Path



def cookie_dict() -> dict:
    """Convert a raw Cookie header string into a dict for requests."""
    with open("cookie_header.txt", "r", encoding="utf-8") as f:
        raw = f.read()
    return dict(p.strip().split("=", 1) for p in raw.split("; ") if "=" in p)

def browserish_headers(shortname: str, code: int | str | None = None):
    suffix = f"/submissions/{code}" if code is not None else ""
    return {
        "User-Agent": "Mozilla/5.0",
        "Accept": "*/*",
        "Referer": f"https://training.olinfo.it/task/{shortname}",
        "rsc": "1",
        "next-url": f"/task/{shortname}{suffix}",
    }



# Per trovare le task cerco:
# bg-green-400 text-success-content" href="{prefisso}/{shortname}">{longname}

_PATTERN = re.compile(
    r'<a'                                                           # tag <a
    r'(?=[^>]*\bclass="[^"]*\bbg-green-400\b[^"]*")'                # contiene classe bg-green-400
    r'(?=[^>]*\bclass="[^"]*\btext-success-content\b[^"]*")'        # contiene classe text-success-content
    r'[^>]*\bhref="(?P<prefisso>[^"]+?)/(?P<shortname>[^"/#?]+)"'   # href="prefisso/shortname"
    r'[^>]*>'                                                       # fine del tag di apertura
    r'\s*(?P<longname>[^<]+?)\s*(?:<|$)',                           # testo visibile fino al prossimo '<'
    re.IGNORECASE | re.DOTALL
)

def get_solved_tasks(username: str = "Glauco"):
    url = f"https://training.olinfo.it/user/{username}"
    res = requests.get(url, cookies=cookie_dict(), timeout=30)
    raw = res.text
    
    risultati = []
    for m in _PATTERN.finditer(raw):
        prefisso   = m.group("prefisso")
        shortname  = m.group("shortname")
        longname   = html.unescape(m.group("longname").strip())
        risultati.append({
            "prefisso": prefisso,
            "shortname": shortname,
            "longname": longname,
        })

    print(f"Found {len(risultati)} fully solved tasks.")
    return risultati


# Per trovare l'ultima sub cerco analoghi a:
# href="/task/ois_aliga/submissions/1194108"><div class="w-20 font-mono">1194108</div><div>C++17 / g++</div><div><!--$!--><template data-dgst="BAILOUT_TO_CLIENT_SIDE_RENDERING"></template><!--/$--></div><div class="min-w-40 text-end"><span class="inline-block rounded-lg px-2 text-sm bg-green-400 text-success-content">100
# href="/task/terry/pile/submissions/e6a04653-2276-4fb7-9928-f586210f160a"><div class="mr-1">e6a04653</div><div>C++</div><div><!--$!--><template data-dgst="BAILOUT_TO_CLIENT_SIDE_RENDERING"></template><!--/$--></div><div class="min-w-40 text-end"><span class="inline-block rounded-lg px-2 text-sm bg-green-400 text-success-content">6

class Task(TypedDict):
    prefisso: str
    shortname: str
    longname: str

def get_code(entry: Task):
    prefisso  = entry["prefisso"]
    shortname = entry["shortname"]

    url = f"https://training.olinfo.it/{prefisso}/{shortname}/submissions"
    res = requests.get(url, cookies=cookie_dict(), timeout=30)
    raw = res.text

    pref = re.escape(prefisso.strip("/"))
    short = re.escape(shortname.strip("/"))

    tail = (
        r'<template\s+data-dgst="BAILOUT_TO_CLIENT_SIDE_RENDERING"></template>'
        r'<!--/\$--></div><div class="min-w-40 text-end"><span '
        r'class="inline-block rounded-lg px-2 text-sm bg-green-400 text-success-content">'
    )

    rx = re.compile(
        rf'href="/?{pref}/?{short}/submissions/'
        rf'(?P<codice_alfanumerico>[0-9A-Za-z_-]+)"'
        r'>'
        r'(?:(?!href=)[\s\S])*?'
        + tail,
        re.IGNORECASE
    )

    m = rx.search(raw)  # prima occorrenza non sovrapposta
    return m.group("codice_alfanumerico")



class Codice(TypedDict):
    task: Task
    code: str

_REF_RE = re.compile(r'"code"\s*:\s*"\$([0-9A-Za-z_]+)"')
_INLINE_RE = re.compile(r'"code"\s*:\s*"((?:\\.|[^"\\])*)"')
_NEXT_LABEL_RE = re.compile(r'(?:(?<=\})|(?<=\n))[0-9A-Za-z_]+:')
_T_PREFIX_RE = re.compile(r'^\s*T[0-9A-Fa-f]+,\s*')

def _label_rx(ref: str) -> re.Pattern:
    return re.compile(rf'(?m)^{re.escape(ref)}:')

def extract_code_and_ext(text: str):
    # Caso A: code referenziato "$<ref>"
    m_ref = _REF_RE.search(text)
    if m_ref:
        ref = m_ref.group(1)

        # trova blocco etichettato <ref>:
        m_label = _label_rx(ref).search(text)
        if not m_label:
            return None, None

        start = m_label.end()
        after = text[start:]
        # rimuovi prefisso "T####," se presente
        after = _T_PREFIX_RE.sub('', after, count=1)
        # ferma al prossimo label
        m_next = _NEXT_LABEL_RE.search(after)
        blob = after[:m_next.start()] if m_next else after
        code = html.unescape(blob).rstrip()

        # lang subito dopo "code"
        m_lang = re.search(r'\blang"\s*:\s*"([a-zA-Z0-9_.+-]+)"',
                           text[m_ref.end(): m_ref.end()+1500])
        ext = m_lang.group(1) if m_lang else None
        return (code or None), ext

    # Caso B: code inline nella stringa JSON
    m_in = _INLINE_RE.search(text)
    if not m_in:
        return None, None

    raw = m_in.group(1)
    try:
        code = json.loads(f'"{raw}"')  # decodifica escape JSON
    except json.JSONDecodeError:
        code = raw.encode('utf-8','backslashreplace').decode('unicode_escape')
    code = _T_PREFIX_RE.sub('', code, count=1).rstrip()

    # lang subito dopo il campo code inline
    m_lang = re.search(r'\blang"\s*:\s*"([a-zA-Z0-9_.+-]+)"',
                       text[m_in.end(): m_in.end()+1500])
    ext = m_lang.group(1) if m_lang else None
    return (code or None), ext



def save_submission(entry: Codice):
    prefisso  = entry["task"]["prefisso"]
    shortname = entry["task"]["shortname"]
    code = entry["code"]

    url = f"https://training.olinfo.it/{prefisso}/{shortname}/submissions/{code}"
    res = requests.get(url, headers=browserish_headers(shortname, code), cookies=cookie_dict(), timeout=30)
    raw = res.text

    code, ext = extract_code_and_ext(raw)

    if code is None or ext is None:
        print("errore " + shortname)
    else:
        path = "src/olinfo/"

        if "terry" in prefisso:
            path += "terry/"

        with open(path + shortname + "." + ext, "w") as f:
            f.write(code)



def main():
    solved_tasks = get_solved_tasks("Glauco")

    codici = []
    for task in solved_tasks:
        codici.append({"task": task, "code": get_code(task)})

    Path("src/olinfo/terry").mkdir(parents=True, exist_ok=True)
    for codice in codici:
        save_submission(codice)


if __name__ == "__main__":
    main()
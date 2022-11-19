#include <bits/stdc++.h>
using namespace std;
ifstream fin("connect.in");
ofstream fout("connect.out");

vector<int> father, s;
int comps;
  
void init(int n){
  father.resize(n);
  s.resize(n, 1);
  iota(father.begin(), father.end(), 0);
  comps = n;
}

int get(int a){
  if(father[a] == a) return a;
  else return get(father[a]);
}

int join(int a, int b){
  int c = get(a), d = get(b);

  if(c != d){
    if(s[c] < s[d]) swap(c, d);

    father[d] = c;
    s[c] += s[d];

    comps--;

    return d;
  }

  return -1;
}

struct st{
  struct node{
    vector<pair<int, int>> v;
  };

  int size = 1;
  vector<node> v;
  vector<int> ans;

  st(int q){
    while(size < q) size *= 2;
    ans.resize(q+3);
    v.resize(2*size);
  }

  void dfs(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return;

    vector<int> reroll;

    for(auto i : v[u].v){
      auto t = join(i.first, i.second);

      if(t != -1) reroll.push_back(t);
    } 

    if(l == r-1){
      ans[u-size] = comps;
    }else{
      dfs(2*u, l, l + (r-l)/2, x, y);
      dfs(2*u+1, l + (r-l)/2, r, x, y);
    }

    for(auto i : reroll){
      s[father[i]] -= s[i];
      father[i] = i;
      comps++;
    }
  }

  void update(int u, int l, int r, int x, int y, pair<int, int> arco){
    if(l >= y || r <= x) return;
    if(l >= x && r <= y){
      v[u].v.push_back(arco);
      return;
    }

    update(2*u, l, l + (r-l)/2, x, y, arco);
    update(2*u+1, l + (r-l)/2, r, x, y, arco);
  }

  void upd(pair<int, int> arco, int l, int r){
    update(1, 0, size, l, r, arco);
  }
};

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int n, q;
  fin >> n >> q;

  st st(q+1);
  init(n);

  vector<pair<pair<int, int>, int>> upd;
  vector<int> query;
  
  char c; int a, b;
  for(int i = 1; i <= q; i++){
    fin >> c;

    if(c == '?') query.push_back(i);
    else{
      fin >> a >> b;
      if(a > b) swap(a, b);
      upd.push_back({{a-1, b-1}, i});
    }
  }

  sort(upd.begin(), upd.end());

  for(int i = 0; i < upd.size(); i++){
    int l = upd[i].second, r = q+2;

    if(i < upd.size()-1 && upd[i].first == upd[i+1].first){
      r = upd[i+1].second;
      i++;
    }

    st.upd(upd[i].first, l, r);
  }

  st.dfs(1, 0, st.size, 0, q+2);

  for(auto i : query) fout << st.ans[i] << endl;
}
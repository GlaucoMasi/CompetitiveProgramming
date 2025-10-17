#include <bits/stdc++.h>
using namespace std;

struct node {
    int fat, sz = 1;
    int c[3];
};

const int maxn = 200000;
node v[maxn];

int get(int a){
    if(a == v[a].fat) return a;
    return v[a].fat = get(v[a].fat);
}


void organizza(int n, string t) {
    for(int i = 0; i < n; i++) v[i].fat = i;
    for(int i = 0; i < n; i++){
        if(t[i] == 'S') v[i].c[0]++;
        else if(t[i] == 'F') v[i].c[1]++;
        else v[i].c[2]++;
    }
}

int sfida(int a, int b) {
    int fa = get(a), fb = get(b);
    long long pta = 0, ptb = 0;
    for(int i = 0; i < 3; i++){
        pta += 1LL*v[fa].c[i]*v[fb].c[(i+1)%3];
        ptb += 1LL*v[fb].c[i]*v[fa].c[(i+1)%3];
    }
    if(pta == ptb) return -1;
    else if(pta > ptb) return a;
    else return b;
}

void allea(int a, int b) {
    a = get(a), b = get(b);
    if(v[a].sz < v[b].sz) swap(a, b);
    v[b].fat = a;
    v[a].sz += v[b].sz;
    for(int i = 0; i < 3; i++) v[a].c[i] += v[b].c[i];
}


#ifndef EVAL

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N, Q; cin >> N >> Q;

    string S; cin >> S;

    organizza(N, S);

    while(Q--) {
        int t, a, b; cin >> t >> a >> b;

        if(t == 2)
            allea(a, b);
        else if(t == 1)
            cout << sfida(a, b) << "\n";
    }
}

#endif
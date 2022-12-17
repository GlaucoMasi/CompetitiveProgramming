#include <bits/stdc++.h>
using namespace std;

vector<int> father, sz;

int get(int a){
  if(a == father[a]) return a;
  else return father[a] = get(father[a]);
}

int main() {
  int n, m; cin >> n >> m;
  father.resize(n); iota(father.begin(), father.end(), 0);
  sz.resize(n, 1);

  int a, b;
  int comp = n, big = 1;
  while(m--){
    cin >> a >> b; a--; b--;

    a = get(a), b = get(b);
    if(a != b){
      if(sz[a] < sz[b]) swap(a, b);

      father[b] = a;
      sz[a] += sz[b];
      comp--;

      big = max(big, sz[a]);
    }

    cout << comp << " " << big << endl;
  }
}
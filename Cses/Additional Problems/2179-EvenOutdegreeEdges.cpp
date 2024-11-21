#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<vector<int>> g;
vector<pair<int, int>> ord;
vector<int> t, even;

void f(int i, int p){
  t[i] = (p == -1 ? 1 : t[p]+1);

  for(auto j : g[i]){
    if(j == p) continue;

    if(!t[j]){
      f(j, i);
      
      if(even[j]){
        ord.push_back({i, j});
        even[i] ^= 1;
      }else{
        ord.push_back({j, i});
        even[j] ^= 1;
      }
    }else if(t[j] < t[i]){
      ord.push_back({i, j});
      even[i] ^= 1;
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m;
  g.resize(n);
  t.resize(n);
  even.resize(n, 1);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  for(int i = 0; i < n; i++){
    if(!t[i]) f(i, -1);
    
    if(!even[i]){
      cout << "IMPOSSIBLE";
      return 0;
    }
  }

  for(auto [a, b] : ord) cout << a+1 << " " << b+1 << '\n';
}
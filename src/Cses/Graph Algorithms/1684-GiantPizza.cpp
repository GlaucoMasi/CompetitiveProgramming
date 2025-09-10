#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<bool> vis;
vector<int> ord, col;
vector<vector<int>> g, inv;

void f(int i){
  vis[i] = 1;
  for(auto j : g[i]) if(!vis[j]) f(j);
  ord.push_back(i);
}

void comp(int i, int idx){
  col[i] = idx;
  for(auto j : inv[i]) if(!col[j]) comp(j, idx);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m;
  g.resize(2*m);
  inv.resize(2*m);
  vis.resize(2*m);
  col.resize(2*m);

  for(int i = 0; i < n; i++){
    char c1, c2; int a, b;
    cin >> c1 >> a >> c2 >> b;
    if(c1 == '+') a += m;
    if(c2 == '+') b += m;
    a--; b--;

    g[(a+m)%(2*m)].push_back(b);
    inv[b].push_back((a+m)%(2*m));
    g[(b+m)%(2*m)].push_back(a);
    inv[a].push_back((b+m)%(2*m));
  }

  int idx = 1;
  for(int i = 0; i < 2*m; i++) if(!vis[i]) f(i);
  for(int i = 2*m-1; i >= 0; i--) if(!col[ord[i]]) comp(ord[i], idx++);

  for(int i = 0; i < m; i++) if(col[i] == col[i+m]){
    cout << "IMPOSSIBLE";
    return 0;
  }

  for(int i = 0; i < m; i++){
    if(col[i] < col[i+m]) cout << "+ ";
    else cout << "- ";
  }
}
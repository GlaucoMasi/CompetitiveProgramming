#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<int>> g;
vector<vector<long long>> c;
vector<int> father;

long long flow(vector<int> &father){
  father = vector<int>(n, -1);
  father[0] = -2;

  queue<pair<int, long long>> q;
  q.push({0, 1e18});
  
  while(!q.empty()){
    int i = q.front().first;
    long long lim = q.front().second;
    q.pop();

    if(i == n-1) return lim;

    for(auto j : g[i]){
      if(father[j] != -1 || !c[i][j]) continue;

      father[j] = i;
      q.push({j, min(lim, c[i][j])});
    }
  }

  return 0;
}

vector<bool> vis;

void f(int i, int last){
  if(father[i] == -1) cout << last+1 << " " << i+1 << endl;
  else{
    vis[i] = 1;

    for(auto j : g[i]){
      if(!vis[j]) f(j, i);
    }
  }
}

int main() {
  cin >> n >> m;

  g.resize(n);
  c.resize(n, vector<long long>(n, 0));
  vis.resize(n);

  int a, b, d;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    a--; b--;

    g[a].push_back(b);
    g[b].push_back(a);
    c[a][b]++;
    c[b][a]++;
  }

  long long tot = 0, t;
  while(t = flow(father)){
    tot += t;

    int i = n-1;
    while(i != 0){
      c[father[i]][i] -= t;
      c[i][father[i]] += t;
      i = father[i];
    }
  }

  cout << tot << endl;
  f(0, -1);
}
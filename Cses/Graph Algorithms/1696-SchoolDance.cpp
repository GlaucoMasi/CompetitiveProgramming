#include <bits/stdc++.h>
using namespace std;

int n, m, k;
vector<vector<int>> g;
vector<vector<long long>> c;
vector<int> father;

long long flow(vector<int> &father){
  father = vector<int>(m+n+2, -1);
  father[0] = -2;

  queue<pair<int, long long>> q;
  q.push({0, 1e18});
  
  while(!q.empty()){
    int i = q.front().first;
    long long lim = q.front().second;
    q.pop();

    if(i == n+m+1) return lim;

    for(auto j : g[i]){
      if(father[j] != -1 || !c[i][j]) continue;

      father[j] = i;
      q.push({j, min(lim, c[i][j])});
    }
  }

  return 0;
}

vector<bool> vis;

void find(int i, int last){
  if(father[i] == -1) cout << last << " " << i << endl;
  else{
    vis[i] = 1;

    for(auto j : g[i]){
      if(!vis[j]) find(j, i);
    }
  }
}

// sorg = 0
// pozzo = m+n+1

int main() {
  cin >> n >> m >> k;

  g.resize(n+m+2);
  c.resize(n+m+2, vector<long long>(n+m+2, 0));
  vis.resize(n+m+2);

  int a, b;
  for(int i = 0; i < k; i++){
    cin >> a >> b;
    b += n;

    if(c[a][b]) continue;

    g[a].push_back(b);
    g[b].push_back(a);
    c[a][b]++;
  }

  for(int i = 0; i < n; i++){
    g[0].push_back(i+1);
    g[i+1].push_back(0);
    c[0][i+1]++;
  }

  for(int i = 0; i < m; i++){
    g[n+m+1].push_back(i+n+1);
    g[i+n+1].push_back(n+m+1);
    c[i+n+1][n+m+1]++;
  }

  long long tot = 0, t;
  while(t = flow(father)){
    tot += t;

    int i = n+m+1;
    while(i != 0){
      c[father[i]][i] -= t;
      c[i][father[i]] += t;
      i = father[i];
    }
  }

  cout << tot << endl;
  for(int i = 1; i <= n; i++){
    for(auto j : g[i]) if(j != 0 && !c[i][j]) cout << i << " " << j-n << endl;
  }
}
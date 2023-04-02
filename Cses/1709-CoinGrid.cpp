#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<vector<long long>> c;
vector<int> father;

long long flow(){
  father = vector<int>(2*n+2, -1);

  queue<pair<int, long long>> q;
  q.push({0, 1e18});
  while(!q.empty()){
    int i = q.front().first; long long lim = q.front().second; q.pop();

    if(i == 2*n+1) return lim;

    for(auto j : g[i]){
      if(father[j] == -1 && c[i][j]){
        father[j] = i;
        q.push({j, min(lim, c[i][j])});
      }
    }
  }

  return 0;
}

int tot;
vector<bool> vis;

void f(int i){
  vis[i] = 1;

  if(i > n) tot++;
  else tot--; 

  for(auto j : g[i]){
    if(j != 0 && j != 2*n+1 && c[i][j] && !vis[j]) f(j);
  }
}

int main() {
  cin >> n;
  g.resize(2*n+2);
  c.resize(2*n+2, vector<long long>(2*n+2));
  vis.resize(2*n+2);

  string a;
  for(int i = 0; i < n; i++){
    cin >> a;

    for(int j = 0; j < n; j++){
      if(a[j] == 'o'){
        g[i+1].push_back(j+n+1);
        g[j+n+1].push_back(i+1);
        c[i+1][j+n+1]++;
      }
    }
  }

  for(int i = 1; i <= n; i++){
    g[0].push_back(i);
    g[i].push_back(0);
    c[0][i]++;

    g[i+n].push_back(2*n+1);
    g[2*n+1].push_back(i+n);
    c[i+n][2*n+1]++;
  }

  long long t;
  while(t = flow()){
    int i = 2*n+1;

    while(i != 0){
      c[father[i]][i] -= t;
      c[i][father[i]] += t;
      i = father[i];
    }
  }

  for(int i = 1; i <= n; i++){
    bool start = 1;

    for(auto j : g[i]){
      if(j != 0 && !c[i][j]) start = 0;
    }

    if(start) f(i);
  }

  tot += n;
  cout << tot << endl;
  for(int i = 1; i <= n; i++) if(!vis[i]) cout << 1 << " " << i << endl;
  for(int i = n+1; i <= 2*n; i++) if(vis[i]) cout << 2 << " " << i-n << endl;
}
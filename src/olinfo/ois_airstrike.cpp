#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
vector<vector<bool>> c;
vector<int> father;

bool flow(){
  father = vector<int>(2*n+2, -1);

  stack<int> q;
  q.push(0);
  while(!q.empty()){
    int i = q.top(); q.pop();

    if(i == 2*n+1) return 1;

    for(auto j : g[i]){
      if(father[j] == -1 && c[i][j]){
        father[j] = i;
        q.push(j);
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
  c.resize(2*n+2, vector<bool>(2*n+2));
  vis.resize(2*n+2);

  int a, b;
  for(int i = 0; i < n; i++){
    cin >> a >> b;
    g[a].push_back(b+n);
    g[b+n].push_back(a);
    c[a][b+n] = 1;
  }

  for(int i = 1; i <= n; i++){
    g[0].push_back(i);
    g[i].push_back(0);
    c[0][i] = 1;

    g[i+n].push_back(2*n+1);
    g[2*n+1].push_back(i+n);
    c[i+n][2*n+1] = 1;
  }

  long long t;
  while(t = flow()){
    int i = 2*n+1;

    while(i != 0){
      c[father[i]][i] = 0;
      c[i][father[i]] = 1;
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
}
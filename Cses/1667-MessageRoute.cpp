#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m;
  cin >> n >> m;

  vector<vector<int>> g(n);
  vector<int> father(n, -1);

  int a, b;
  for(int i = 0; i < m; i++){
    cin >> a >> b;
    a--; b--;

    g[a].push_back(b);
    g[b].push_back(a);
  }

  queue<pair<int, int>> q;
  q.push({0, 0});
  while(!q.empty()){
    int i = q.front().first, fat = q.front().second; q.pop();

    if(father[i] != -1) continue;
    father[i] = fat;  

    if(i == n-1){
      vector<int> path;
    
      while(i != 0){
        path.push_back(i);
        i = father[i];
      }
      path.push_back(0);

      cout << path.size() << endl;
      for(int i = path.size()-1; i >= 0; i--) cout << path[i]+1 << " ";

      return 0;
    }

    for(auto j : g[i]){
      if(father[j] == -1) q.push({j, i});
    }
  }

  cout << "IMPOSSIBLE";
}
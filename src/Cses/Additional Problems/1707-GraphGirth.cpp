#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<vector<int>> g;

int test(int start){
  vector<int> dist(n), fat(n, -1);
  queue<int> q; q.push(start);

  int ans = 1e9;
  while(!q.empty()){
    int i = q.front(); q.pop();
    
    for(auto j : g[i]){
      if(fat[j] == -1){
        fat[j] = i;
        dist[j] = dist[i]+1;
        q.push(j);
      }else if(fat[j] != i && fat[i] != j) ans = min(ans, dist[i]+dist[j]+1);
    }
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m;

  g.resize(n);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  int best = 1e9;
  for(int i = 0; i < n; i++) best = min(best, test(i));
  cout << (best == 1e9 ? -1 : best);
}
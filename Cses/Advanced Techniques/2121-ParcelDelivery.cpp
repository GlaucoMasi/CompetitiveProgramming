#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, k;
vector<int> forw, back;
vector<vector<array<int, 3>>> g;

int flow(vector<pair<int, int>> &fat){
  vector<int> dist(n, 1e9);
  vector<bool> in(n);
  queue<int> q;

  in[0] = 1;
  dist[0] = 0;
  q.push(0);
  while(!q.empty()){
    int i = q.front(); q.pop();
    in[i] = 0;

    for(auto [j, cost, idx] : g[i]){
      if((idx > 0 && !forw[idx]) || (idx < 0 && !back[-idx])) continue;
      if(dist[j] <= dist[i]+cost) continue;

      fat[j] = {i, idx};
      dist[j] = dist[i]+cost;
      if(!in[j]) q.push(j);
      in[j] = 1;
    }
  }

  return dist[n-1];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m >> k;
  forw.resize(m+1);
  back.resize(m+1);
  g.resize(n);

  for(int i = 1; i <= m; i++){
    int a, b, cap, cost; cin >> a >> b >> cap >> cost;
    g[--a].push_back({--b, cost, i});
    g[b].push_back({a, -cost, -i});
    forw[i] = cap;
  }
  
  vector<pair<int, int>> fat(n, {-1, -1});
  int tot = 0, cost = 0, curr;
  while(tot < k && (curr = flow(fat)) != 1e9){
    cost += curr; tot++;

    int i = n-1;
    while(i != 0){
      auto [prev, idx] = fat[i];

      if(idx > 0){
        forw[idx]--;
        back[idx]++;
      }else{
        forw[-idx]++;
        back[-idx]--;
      }

      i = prev;
    }
  }

  if(tot < k) cout << -1;
  else cout << cost;
}

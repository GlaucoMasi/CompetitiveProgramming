#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, c;
vector<vector<int>> g;
vector<long long> cost;
vector<vector<long long>> dp, skipped;

void f(int i){
  priority_queue<pair<long long, pair<int, int>>> pq;

  for(auto j : g[i]){
    f(j);
    pq.push({dp[j][0], {j, 0}});
  }

  skipped[i][0] = 2e18; 
  dp[i][0] = cost[i]+(pq.empty() ? 0 : pq.top().first);

  for(int j = 1; j <= c; j++){
    dp[i][j] = dp[i][j-1];
    
    if(!pq.empty()){
      auto [c, temp] = pq.top();
      auto [node, status] = temp;
      pq.pop();

      dp[i][j] -= c;
      pq.push({dp[node][status+1], {node, status+1}});
      dp[i][j] += pq.top().first;
    }

    skipped[i][j] = dp[i][j-1]-cost[i];
  }

  for(int j = 0; j <= c; j++) dp[i][j] = min(dp[i][j], skipped[i][j]);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> c;
  dp.resize(n, vector<long long>(c+1));
  skipped.resize(n, vector<long long>(c+1));
  cost.resize(n);
  g.resize(n);

  int root;
  for(int i = 0; i < n; i++){
    int p; cin >> p >> cost[i];
    if(p == -1) root = i;
    else g[p].push_back(i);
  }

  f(root);
  cout << dp[root][c];
}
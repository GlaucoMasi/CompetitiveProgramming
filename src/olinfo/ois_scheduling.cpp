#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> c;

int dfs(vector<int> &fat){
  fill(fat.begin(), fat.end(), -1);

  stack<pair<int, int>> st;
  st.push({0, 1e9});
  while(!st.empty()){
    int node = st.top().first, flow = st.top().second;
    st.pop();

    if(node == n+1) return flow;
  
    for(int i = 1; i <= n+1; i++){
      if(c[node][i] && fat[i] == -1){
        fat[i] = node;
        st.push({i, min(flow, c[node][i])});
      }
    }
  }

  return 0;
}

int maxflow(){
  vector<int> fat(n+2);

  int ans = 0, flow;
  while(flow = dfs(fat)){
    ans += flow;

    int curr = n+1;
    while(curr != 0){
      c[fat[curr]][curr] -= flow;
      c[curr][fat[curr]] += flow;

      curr = fat[curr];
    }
  }

  return ans;
}

int main() {
  cin >> n;
  c.resize(n+2, vector<int>(n+2, 0));

  for(int i = 1; i <= n; i++) cin >> c[0][i];
  for(int i = 1; i <= n; i++) cin >> c[i][n+1];
  for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) cin >> c[i][j];

  cout << maxflow();
}
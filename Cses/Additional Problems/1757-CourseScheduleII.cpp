#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<int> out;
vector<vector<int>> g;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m;
  g.resize(n);
  out.resize(n);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[--b].push_back(--a);
    out[a]++;
  }

  priority_queue<int> pq;
  for(int i = 0; i < n; i++) if(!out[i]) pq.push(i);

  vector<int> ans;
  while(!pq.empty()){
    int i = pq.top(); pq.pop();

    ans.push_back(i+1);
    
    for(auto j : g[i]){
      out[j]--;
      if(!out[j]) pq.push(j);
    }
  }

  for(int i = n-1; i >= 0; i--) cout << ans[i] << " ";
}
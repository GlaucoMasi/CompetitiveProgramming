#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<vector<int>> g;

vector<int> f(int start){
  vector<int> dist(n, 1e9);
  queue<int> q;

  q.push(start); dist[start] = 0;
  while(!q.empty()){
    int i = q.front(); q.pop();
    
    for(auto j : g[i]){
      if(dist[j] > dist[i]+1){
        dist[j] = dist[i]+1;
        q.push(j);
      }
    }
  }

  return dist;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m;
  g.resize(n);

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  vector<int> start = f(0), end = f(n-1);

  vector<int> pref(n+1);
  for(auto i : end) pref[i]++;
  for(int i = 1; i <= n; i++) pref[i] += pref[i-1];
  
  long long tot = 0;
  for(int i = 0; i < n; i++) if(start[n-1]-start[i]-2 >= 0) tot += pref[start[n-1]-start[i]-2];

  cout << (long long)n*(n-1)/2-m-tot;
}
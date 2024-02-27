#include <bits/stdc++.h>
using namespace std;

int n, k, maxl;
long long ans = 0;
vector<int> g[200001];
bool removed[200001];
int sz[200001], dist[200001];
vector<int> buffer;

int dfs(int i, int f){
  sz[i] = 1;
  for(auto j : g[i]) if(j != f && !removed[j]) sz[i] += dfs(j, i);;
  return sz[i];
}

void count(int i, int f, int l){
  if(l > k) return;
  ans += dist[k-l];
  buffer.push_back(l); maxl = max(maxl, l);

  for(auto j : g[i]) if(j != f && !removed[j]) count(j, i, l+1);
}

void decomp(int idx){
  dfs(idx, -1);

  bool found = 0;
  int centr = idx, f = -1;
  while(!found){
    found = 1;
    for(auto j : g[centr]) if(j != f && !removed[j] && sz[j] > sz[idx]/2){
      f = centr, centr = j;
      found = 0;
      break;
    }
  }

  maxl = 0;

  for(auto i : g[centr]){
    if(removed[i]) continue;
    count(i, centr, 1);
    for(auto j : buffer) dist[j]++;
    buffer.clear();
  }

  for(int i = 1; i <= maxl; i++) dist[i] = 0;
  removed[centr] = 1;
  for(auto i : g[centr]) if(!removed[i]) decomp(i);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> k;
  dist[0] = 1;

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  if(k == n){
    cout << 0;
    return 0;
  }

  decomp(0);
  cout << ans;
}
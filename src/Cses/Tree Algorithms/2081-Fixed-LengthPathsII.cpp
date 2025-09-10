#include <bits/stdc++.h>
using namespace std;

int n, k1, k2, maxl;
long long ans = 0;
vector<int> g[200001];
bool removed[200001];
int sz[200001];
int fen[200001];
vector<int> buffer;

void upd(int i, int add){
  i++;
  while(i <= 200000){
    fen[i] += add;
    i += (i&-i);
  }
}

int query(int i){
  int ans = 0; i++;
  while(i > 0){
    ans += fen[i];
    i -= (i&-i);
  }
  return ans;
}

int get(int l, int r){ return query(r) - query(l-1); }

int dfs(int i, int f){
  sz[i] = 1;
  for(auto j : g[i]) if(j != f && !removed[j]) sz[i] += dfs(j, i);;
  return sz[i];
}

void count(int i, int f, int l){
  if(l > k2) return;
  ans += get(k1-l, k2-l);
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

  int j = 0;
  for(auto i : g[centr]){
    if(removed[i]) continue;
    count(i, centr, 1);
    for(j; j < buffer.size(); j++) upd(buffer[j], 1);
  }

  for(auto i : buffer) upd(i, -1); buffer.clear();
  removed[centr] = 1;
  for(auto i : g[centr]) if(!removed[i]) decomp(i);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> k1 >> k2;
  upd(0, 1);

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  decomp(0);
  cout << ans;
}
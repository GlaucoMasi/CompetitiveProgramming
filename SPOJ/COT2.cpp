#include <bits/stdc++.h>
using namespace std;

int n, m, LOG;
vector<int> v, ord, depth;
vector<vector<int>> g;
vector<vector<int>> fat;
vector<pair<int, int>> idx;

void f(int i, int p){
  fat[i][0] = p;
  if(i != 0) depth[i] = depth[p]+1;
  for(int j = 1; j < LOG; j++){
    if(fat[i][j-1] == -1) break;
    fat[i][j] = fat[fat[i][j-1]][j-1];
  }

  ord.push_back(i);
  idx[i].first = ord.size()-1;
  for(auto j : g[i]) if(j != p) f(j, i);
  ord.push_back(i);
  idx[i].second = ord.size()-1;
}

constexpr int bl = 512;
bool c(const array<int, 5> &a, const array<int, 5> &b){
  if(a[0]/bl != b[0]/bl) return a[0] < b[0];

  if((a[0]/bl)%2) return a[1] > b[1];
  else return a[1] < b[1];
}

int calc(int a, int b){
  if(depth[b] > depth[a]) swap(a, b);
  int k = depth[a]-depth[b];

  for(int j = 0; j < LOG; j++) if(k & (1<<j)) a = fat[a][j];

  if(a == b) return a;

  for(int j = LOG-1; j >= 0; j--){
    if(fat[a][j] != fat[b][j]){
      a = fat[a][j];
      b = fat[b][j];
    }
  }

  return fat[a][0];
}

int main() {
  cin >> n >> m; LOG = log2(n)+2;
  v.resize(n);
  for(auto &i : v) cin >> i;

  g.resize(n);
  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  fat.resize(n, vector<int>(LOG, -1));
  depth.resize(n);
  idx.resize(n);
  f(0, -1);

  vector<int> ans(m);
  vector<array<int, 5>> quer(m);
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b; a--; b--;

    if(a == b){
      ans[i] = 1;
      continue;
    }

    if(depth[a] > depth[b]) swap(a, b);
    if(idx[a].first < idx[b].first && idx[a].second > idx[b].second) quer[i] = {idx[a].first, idx[b].first, a, b, i};
    else{
      if(idx[a].second < idx[b].first) quer[i] = {idx[a].second, idx[b].first, a, b, i};
      else quer[i] = {idx[b].second, idx[a].first, a, b, i};
    }
  }
  sort(quer.begin(), quer.end(), c);

  int idx = 0;
  map<int, int> mp;
  for(auto &i : v){
    if(!mp.count(i)) mp[i] = idx++;
    i = mp[i];
  }

  int t = 1;
  int l = 0, r = 0;
  vector<int> status(n); status[ord[0]] = 1;
  vector<int> freq(idx); freq[v[ord[0]]] = 1;
  for(auto q : quer){
    int l1 = q[0], r1 = q[1], a = q[2], b = q[3], i = q[4];

    while(l1 < l){
      l--;
      if(status[ord[l]] == 1){
        freq[v[ord[l]]]--;
        if(freq[v[ord[l]]] == 0) t--;
        status[ord[l]] = 2;
      }else if(status[ord[l]] == 0){
        freq[v[ord[l]]]++;
        if(freq[v[ord[l]]] == 1) t++;
        status[ord[l]] = 1;
      }
    }
      
    while(r1 > r){
      r++;

      if(status[ord[r]] == 1){
        freq[v[ord[r]]]--;
        if(freq[v[ord[r]]] == 0) t--;
        status[ord[r]] = 2;
      }else if(status[ord[r]] == 0){
        freq[v[ord[r]]]++;
        if(freq[v[ord[r]]] == 1) t++;
        status[ord[r]] = 1;
      }
    }

    while(l1 > l){
      if(status[ord[l]] == 2){
        freq[v[ord[l]]]++;
        if(freq[v[ord[l]]] == 1) t++;
        status[ord[l]] = 1;
      }else if(status[ord[l]] == 1){
        freq[v[ord[l]]]--;
        if(freq[v[ord[l]]] == 0) t--;
        status[ord[l]] = 0;
      }
      
      l++;
    }

    while(r1 < r){
      if(status[ord[r]] == 2){
        freq[v[ord[r]]]++;
        if(freq[v[ord[r]]] == 1) t++;
        status[ord[r]] = 1;
      }else if(status[ord[r]] == 1){
        freq[v[ord[r]]]--;
        if(freq[v[ord[r]]] == 0) t--;
        status[ord[r]] = 0;
      }

      r--;
    }

    ans[i] = t;
    int lca = calc(a, b);
    if(lca != a && lca != b && freq[v[lca]] == 0) ans[i]++;
  }

  for(auto i : ans) cout << i << '\n';
}
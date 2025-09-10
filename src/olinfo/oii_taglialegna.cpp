#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void Abbatti(int indice, int direzione);

int sz = 1;
vector<int> v;

void init(int n){
  while(sz < n) sz *= 2;
  v.resize(2*sz);
}

void upd(int u, int k){
  u += sz;
  v[u] = k;

  while(u > 1){
    u /= 2;
    v[u] = max(v[2*u], v[2*u+1]);
  }
}

int get(int x, int y, int u = 1, int l = 0, int r = sz){
  if(l >= y || r <= x) return v[0];
  if(l >= x && r <= y) return v[u];
  return max(
    get(x, y, 2*u, l, (l+r)/2),
    get(x, y, 2*u+1, (l+r)/2, r)
  );
}

void Pianifica(int n, int altezza[]){
  init(n);
  vector<int> left(n), right(n);

  right[n-1] = n-1; upd(n-1, n-1);
  for(int i = n-2; i >= 0; i--){
    right[i] = max(i, get(i, min(n, i+altezza[i])));
    upd(i, right[i]);
  }

  for(auto &i : v) i = 1-n;
  left[0] = 0; upd(0, 0);

  for(int i = 1; i < n; i++){
    left[i] = -max(-i, get(max(0, i-altezza[i]+1), i+1));
    upd(i, -left[i]);
  }

  priority_queue<array<int, 3>> pq;
  vector<pair<int, int>> dp(n, {1e9, -1});
  for(int i = 0; i < n; i++){
    while(!pq.empty() && pq.top()[1] < i) pq.pop();
    if(!pq.empty()) dp[i] = {-pq.top()[0]+1, pq.top()[2]};

    if(left[i] == 0) dp[i] = min(dp[i], {1, -1});
    else dp[i] = min(dp[i], {1+dp[left[i]-1].first, -1});

    pq.push({(i ? -dp[i-1].first : 0), right[i], i});
  }

  int i = n-1;
  while(i >= 0){
    if(dp[i].second == -1){
      Abbatti(i, 0);
      i = left[i]-1;
    }else{
      Abbatti(dp[i].second, 1);
      i = dp[i].second-1;
    }
  }
}
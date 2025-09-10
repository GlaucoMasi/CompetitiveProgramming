#include <bits/stdc++.h>
using namespace std;

int n, mod = 998244353;
vector<int> v, sum, fat;
vector<vector<int>> g;

vector<pair<int, int>> buffer;

void f(int i, int p){
  fat[i] = p;
  for(auto j : g[i]) if(j != p) f(j, i);
}

void done() {
  vector<int> temp(n);
  for(auto [node, val] : buffer) temp[node] = (temp[node]+val)%mod;

  for(int i = 0; i < n; i++) for(auto j : g[i]) v[j] = (v[j]+temp[i])%mod;

  for(auto &i : sum) i = 0;
  for(int i = 0; i < n; i++) for(auto j : g[i]) sum[i] = (sum[i] + v[j])%mod;

  buffer.clear();
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n;

  v.resize(n); sum.resize(n); fat.resize(n+1, n);
  for(auto &i : v) cin >> i;

  g.resize(n);
  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }

  f(0, n);
  for(int i = 0; i < n; i++) for(auto j : g[i]) sum[i] = (sum[i] + v[j])%mod;

  int k = 512;
  int q; cin >> q;
  for(int i = 0; i < q; i++){
    int t, x; cin >> t >> x; x--;

    if(t == 1){
      int curr = v[x];
      for(auto [node, val] : buffer) if(fat[node] == x || fat[x] == node) curr = (curr+val)%mod;
      buffer.push_back({x, curr});
      sum[x] = (sum[x]+(long long)(curr*g[x].size()))%mod;

      if(buffer.size() >= k) done();
    }else{
      int ans = 0;
      for(auto [node, val] : buffer) if(x != node && (fat[fat[node]] == x || fat[fat[x]] == node || fat[x] == fat[node]))  ans = (ans+val)%mod;
      cout << (sum[x]+ans)%mod << '\n';
    }
  }
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int mod = 1e9+7;

int exp(int a, int b){
  int ans = 1;
  for(; b; b >>= 1){
    if(b&1) ans = (long long)ans*a%mod;
    a = (long long)a*a%mod;
  }
  return ans;
}

int idx = 0, n, d;
vector<vector<long long>> pref;
vector<pair<int, int>> pos;

void f(int i, int c, int j, vector<int> &a){
  pref[c].push_back((pref[c].back()*a[i])%mod);
  pos[i] = {c, j};
  if(pos[(i-d+n)%n].first == -1) f((i-d+n)%n, c, j+1, a);
}

vector<int> execute(int N, int k, int D, vector<int> a){
  ios::sync_with_stdio(0); fin.tie(0); cout.tie(0);
  n = N; d = D;

  pos.resize(n, {-1, -1});
  for(int i = 0; i < n; i++){
    if(pos[i].first != -1) continue;
    pref.push_back({1});
    f(i, idx++, 1, a);
  }

  k--;
  for(int i = 0; i < n; i++){
    auto [c, j] = pos[i];
    int sz = pref[c].size()-1;
    long long ans = exp(pref[c].back(), k/sz);
    
    int l = j-1, r = (j+k%sz);
    long long temp = (r < pref[c].size() ? (pref[c][r]*exp(pref[c][l], mod-2))%mod : (((pref[c][r%sz]*pref[c].back())%mod)*exp(pref[c][l], mod-2))%mod);
    a[i] = (ans*temp)%mod;
  }
  
  return a;
}
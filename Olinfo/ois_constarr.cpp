#include <bits/stdc++.h>
using namespace std;

int constexpr mod = 1e9+7;
long long n, m, l, r, k;

vector<int> merge(vector<int> a, vector<int> b){
  vector<int> ans(m, 0);

  for(int i = 0; i < m; i++){
    for(int j = 0; j < m; j++){
      int idx = i-j; if(idx < 0) idx += m;
      long long t = a[j]; t = t*b[idx]; t = t-t/mod*mod;
      ans[i] += t; ans[i] = ans[i]-ans[i]/mod*mod;
    }
  }

  return ans;
}

vector<int> base;
vector<int> exp(long long len){
  if(len == 1) return base;

  vector<int> temp = exp(len/2);
  temp = merge(temp, temp);
  if(len&1) temp = merge(temp, base);

  return temp;
}

int main() {
  cin >> n >> m >> l >> r >> k;

  k -= ((n%m)*l)%m; k = (k+m)%m;
  r -= l; l = 0;

  base.resize(m, 0);
  for(int i = 0; i < m && i <= r; i++) base[i] = ((r-i)/m+1)%mod;

  vector<int> ans = exp(n);
  cout << ans[k];
}
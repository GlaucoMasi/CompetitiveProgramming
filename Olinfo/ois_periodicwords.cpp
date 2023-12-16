#include <bits/stdc++.h>
using namespace std;

uint64_t b = 29;

int main() {
  int n, q; cin >> n;
  string a; cin >> a;

  vector<vector<int>> divs(n+1, {1});
  for(int i = 2; i <= n; i++) for(int j = 2*i; j <= n; j += i) divs[j].push_back(i);

  vector<uint64_t> pows(n+1), hash(n+1);
  hash[0] = 0; pows[0] = 1;
  for(int i = 0; i < n; i++){
    pows[i+1] = pows[i]*b;
    hash[i+1] = hash[i] + (a[i]-'a'+1)*pows[i];
  }

  auto get = [&](int l, int r){ return (hash[r+1]-hash[l])*pows[n-r]; };

  cin >> q;
  while(q--){
    int l, r; cin >> l >> r;
    bool ok = 0;

    for(auto d : divs[r-l+1]){
      uint64_t g1 = get(l, r-d), g2 = get(l+d, r);
      if(g1 == g2) ok = 1;
    }

    cout << (ok ? "YES\n" : "NO\n");
  }
}
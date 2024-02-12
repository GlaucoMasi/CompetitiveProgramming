#include <bits/stdc++.h>
using namespace std;

const int k = 1;
array<int, k> b = {29}, mod = {1000000007};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  string a, b; cin >> a >> b;
  for(auto &i : b) i = (i == '0' ? '1' : '0');

  vector<vector<long long>> p(n+1, vector<long long>(k));
  for(int j = 0; j < k; j++){
    p[0][j] = 1;
    for(int i = 1; i <= n; i++) p[i][j] = (p[i-1][j]*b[j])%mod[j];
  }

  vector<vector<int>> hasha, hashb;
  auto chash = [&](string &a, vector<vector<int>> &hash){
    hash.resize(a.size()+1, vector<int>(k));
    for(int i = 1; i <= a.size(); i++) for(int j = 0; j < k; j++) hash[i][j] = (hash[i-1][j] + (a[i-1] == '1')*p[i-1][j])%mod[j];
  };

  chash(a, hasha); chash(b, hashb);

  auto get = [&](vector<vector<int>> &hash, int x, int l, int j){ return (hash[x+l][j]-hash[x][j]+mod[j])%mod[j]; };

  auto comp = [&](int x, int y, int l){
    bool equal = 1;

    for(int i = 0; i < k; i++){
      auto hash1 = get(hasha, x, l, i), hash2 = get(hashb, y, l, i);
      if(x > y) hash2 = (hash2*p[x-y][i])%mod[i];
      if(y > x) hash1 = (hash1*p[y-x][i])%mod[i];
      equal &= (hash1 == hash2);
    }

    return equal;
  };

  int q; cin >> q;
  while(q--){
    int x, y, len; cin >> x >> y >> len;
    
    int l = 0, r = len+1;
    while(l < r-1){
      int m = (l+r)/2;

      if(comp(x, y, m)) l = m;
      else r = m;
    }

    cout << (l == len || a[x+l] == '0') << " ";
  }
}
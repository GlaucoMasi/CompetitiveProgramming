#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int mod = 1e9+7;
long long fen[200001];

void upd(int i, long long k){
  i++;
  while(i <= 2e5){
    fen[i] = (fen[i]+k)%mod;
    i += (i&-i);
  }
}

long long get(int i){
  long long ans = 0;

  while(i > 0){
    ans = (ans+fen[i])%mod;
    i -= (i&-i);
  }

  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> v(n);
  for(auto &i : v) cin >> i;

  vector<int> comp = v;
  unordered_map<int, int> m;
  sort(comp.begin(), comp.end());
  for(int i = 0; i < n; i++) m[comp[i]] = i;
  for(auto &i : v) i = m[i];

  long long ans = 0;
  for(int i = 0; i < n; i++){
    long long t = (get(v[i])+1)%mod;
    ans = (ans+t)%mod;
    upd(v[i], t);
  }

  cout << ans;
}
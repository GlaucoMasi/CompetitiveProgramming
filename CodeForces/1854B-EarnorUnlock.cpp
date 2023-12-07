#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main() {
  ll n; cin >> n;
  vector<ll> v(n);
  for(auto &i : v) cin >> i;

  n *= 2;
  while(v.size() < n) v.push_back(0);

  bitset<200001> b; b.set(0, 1);
  ll cum = 0, best = 0;
  for(ll i = 0; i < n; i++){
    cum += v[i]; b = (b | (b<<v[i]));
    if(b[i]) best = max(best, cum-i);

    b[i] = 0;
  }

  cout << best;
}
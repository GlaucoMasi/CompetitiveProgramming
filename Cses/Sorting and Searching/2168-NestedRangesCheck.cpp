#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<array<int, 3>> v(n);
  vector<bool> in(n), out(n);
  for(int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1], v[i][2] = i, v[i][1] = -v[i][1];
  sort(v.begin(), v.end());

  int best = 0;
  for(auto [l, r, idx] : v){
    in[idx] = best >= -r;
    best = max(best, -r);
  }

  for(auto &[l, r, idx] : v) l = -l, r = -r, swap(l, r);
  sort(v.begin(), v.end());
  
  best = 0;
  for(auto [r, l, idx] : v){
    out[idx] = best >= -l;
    best = max(best, -l);
  }

  for(auto i : out) cout << i << " "; cout << '\n';
  for(auto i : in) cout << i << " "; cout << '\n';
}
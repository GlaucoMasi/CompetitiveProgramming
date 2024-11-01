#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<pair<int64_t, int64_t>> v(n);
  for(auto &[a, b] : v) cin >> a >> b;

  int64_t ans = 0, pts = 0, t = 2;
  for(int i = 0; i < n; i++){
    int j = (i+1)%n;
    pts += __gcd(abs(v[i].first-v[j].first), abs(v[i].second-v[j].second));
    ans += v[i].first*v[j].second-v[i].second*v[j].first;
  }

  cout << (abs(ans)-pts)/t+1 << " " << pts;
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<pair<long long, long long>> v(n);
  for(auto &[a, b] : v) cin >> a >> b;

  long long ans = 0;
  for(int i = 0; i < n; i++){
    int j = (i+1)%n;
    ans += v[i].first*v[j].second-v[i].second*v[j].first;
  }

  cout << abs(ans);
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

bool comp(const pair<long long, long long> &l, const pair<long long, long long> &r){
  auto [a1, d1] = l;
  auto [a2, d2] = r;

  return (d1-a1 + d2-(d1+a1)) > (d2-a2 + d1-(d2+a2));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<pair<long long, long long>> v;
  for(int i = 0; i < n; i++){
    int a, d; cin >> a >> d;
    v.push_back({a, d});
  }

  sort(v.begin(), v.end(), comp);
  
  long long t = 0, ans = 0;
  sort(v.begin(), v.end());
  for(auto [a, d] : v){
    ans += d-(t+a);
    t += a;
  }

  cout << ans;
}
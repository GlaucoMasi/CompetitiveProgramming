#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;
  vector<pair<int, int>> v; v.push_back({1e9, 0});
  for(int i = 0; i < n; i++){
    int a; fin >> a;
    v.push_back({a, i});
  }
  sort(v.begin(), v.end(), greater<>());

  long long ans = 0;
  for(int i = 0; i < n; i++) ans += abs(v[i+1].second-v[i].second);
  fout << ans;
}
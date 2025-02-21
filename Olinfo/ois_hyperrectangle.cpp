#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> v(n); for(auto &i : v) cin >> i;
  sort(v.begin(), v.end());
  for(auto i : v) cout << i << " ";
}
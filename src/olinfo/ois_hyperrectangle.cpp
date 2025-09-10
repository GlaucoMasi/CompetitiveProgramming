#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; cin >> n;
  vector<int> v(2*n); for(auto &i : v) cin >> i;
  sort(v.begin(), v.end());
  for(int i = 0; i < n; i++) cout << v[i] << " "; cout << '\n';
  for(int i = n; i < 2*n; i++) cout << v[i] << " ";
}
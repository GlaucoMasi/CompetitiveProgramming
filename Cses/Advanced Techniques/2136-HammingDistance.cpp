#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, k; cin >> n >> k;
  vector<int> v;

  string s;
  for(int i = 0; i < n; i++){
    int t = 0; cin >> s;
    for(int j = 0; j < k; j++) t += (s[j] == '1')*(1<<j);
    v.push_back(t);
  }

  int best = 32;
  for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++) best = min(best, __popcount(v[i]^v[j]));
  cout << best;
}
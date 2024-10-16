#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, k; cin >> n >> k;
  map<int, pair<int, int>> m;
  vector<int> v(n); for(auto &i : v) cin >> i;

  for(int i = 0; i < n; i++){
    for(int j = i+1; j < n; j++) if(m.count(k-v[i]-v[j])){
      cout << i+1 << " " << j+1 << " " << m[k-v[i]-v[j]].first+1 << " " << m[k-v[i]-v[j]].second+1;
      return 0;
    }

    for(int j = 0; j < i; j++) m[v[i]+v[j]] = {i, j};
  }

  cout << "IMPOSSIBLE";
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, x; cin >> n >> x;
  vector<int> v(n); for(auto &i : v) cin >> i;
  sort(v.begin(), v.end(), greater<>());

  int ans = 0;
  for(int i = 0; i < v.size(); i++){
    ans++;
    if(v[i]+v.back() <= x && i != v.size()-1) v.pop_back();
  }

  cout << ans;
}
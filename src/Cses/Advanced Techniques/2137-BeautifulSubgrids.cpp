#include <bits/stdc++.h>
#pragma GCC target("popcnt")
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<bitset<3000>> v(n);

  for(int i = 0; i < n; i++){
    string s; cin >> s;
    for(int j = 0; j < n; j++) v[i][j] = s[j] == '1';
  }

  long long ans = 0;
  for(int i = 0; i < n; i++) for(int j = i+1; j < n; j++){
    auto temp = v[i]&v[j];
    long long cnt = temp.count();
    ans += cnt*(cnt-1)/2;
  }

  cout << ans;
}
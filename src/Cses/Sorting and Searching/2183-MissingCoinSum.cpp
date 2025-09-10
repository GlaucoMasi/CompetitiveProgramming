#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; cin >> n;
  vector<int> v(n);
  for(auto &i : v) cin >> i;
  sort(v.begin(), v.end());

  long long ans = 1;
  for(auto i : v){
    if(i <= ans) ans += i;
    else{
      cout << ans;
      return 0;
    }
  }

  cout << ans;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  string a; cin >> a;
  int mod = 1e9+7;

  long long ans = a[a.size()-1]-'a', pows26 = 26;
  for(int lenght = 1; lenght < a.size(); lenght++){
    ans = (ans + pows26 + (a[a.size()-lenght-1]-'a')*pows26)%mod;
    pows26 = (pows26*26)%mod;
  }

  cout << ans;
}
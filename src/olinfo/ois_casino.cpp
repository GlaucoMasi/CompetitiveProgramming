#include <bits/stdc++.h>
using namespace std;

string conv(string a){
  a += a; int n = a.size();
  int ans = 0, i = 0;

  while(i < n/2){
    int j = i+1, k = i;
    ans = i;

    while(j < n && a[k] <= a[j]){
      if(a[k] < a[j]) k = i;
      else k++;
      
      j++;
    }

    while(i <= k) i += j-k;
  }

  return a.substr(ans, n/2);
}

int main() {
  int n, l; cin >> n >> l;

  long long ans = 0;
  map<string, int> mp;
  while(n--){
    string a; cin >> a;
    ans += mp[conv(a)]++;
  }

  cout << ans;
}
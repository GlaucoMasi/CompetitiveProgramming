#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);

  int q;
  long long n;
  cin >> n >> q;

  vector<long long> out(n);
  long long ans = n*(n-1)*(n-2)/6;
  for(int i = 0; i < n; i++){
    out[i] = n-i-1;
    ans -= out[i]*(out[i]-1)/2;
  }

  while(q--){
    int a, b;
    cin >> a >> b;

    ans += out[--a]*(out[a]-1)/2;
    ans += out[--b]*(out[b]-1)/2;
    out[a]--; out[b]++;
    ans -= out[a]*(out[a]-1)/2;
    ans -= out[b]*(out[b]-1)/2;
  
    cout << ans << '\n';
  }
}
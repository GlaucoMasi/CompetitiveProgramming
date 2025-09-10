#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;

  int ans = 0;
  vector<bool> prime(n+1, 1);
  for(long long i = 2; i <= n; i++) if(prime[i]){
    ans++;
    for(long long j = i*i; j <= n; j += i) prime[j] = 0;
  }

  cout << ans;
}
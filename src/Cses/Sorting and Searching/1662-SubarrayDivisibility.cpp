#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; cin >> n;
  map<long long, int> m; m[0] = 1;

  long long ans = 0, tot = 0;
  for(int i = 0; i < n; i++){
    int a; cin >> a; tot += a;
    tot = (tot%n+n)%n;
    ans += m[tot]++;
  }

  cout << ans;
}
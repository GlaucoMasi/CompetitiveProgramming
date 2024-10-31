#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t, n; cin >> t;
  while(t--){
    cin >> n;
    int ans = 0;
    while(n--){
      int a; cin >> a;
      ans ^= (a%4);
    }

    if(!ans) cout << "second\n";
    else cout << "first\n";
  }
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while(t--){
    int n, x = 0; cin >> n;

    for(int i = 1; i <= n; i++){
      int a; cin >> a;
      if(!(i%2)) x ^= a;
    }

    cout << (x ? "first\n" : "second\n");
  }
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    bool win = 0;
    while(n--){
      int a; cin >> a;
      if(a%2) win = 1;
    }

    cout << (win ? "first\n" : "second\n");
  }
}
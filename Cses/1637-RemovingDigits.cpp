#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; cin >> n;

  int tot = 0;
  while(n > 0){
    tot++;
    int t = n, digit = 0;

    while(t){
      digit = max(digit, t % 10);
      t /= 10;
    }

    n -= digit;
  }

  cout << tot;
}
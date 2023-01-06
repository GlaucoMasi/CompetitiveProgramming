#include <bits/stdc++.h>
using namespace std;

int main() {
  long long r, c, k;
  cin >> r >> c >> k;
  cout << (r/k+(r%k != 0))*(c/k + (c%k != 0));
}
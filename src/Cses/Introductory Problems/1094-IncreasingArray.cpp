#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;

  long long count = 0;
  int last = 0, a;
  for(int i = 0; i < n; i++){
    cin >> a;
    if(a < last) count += last-a;
    else last = a;
  }

  cout << count;
}
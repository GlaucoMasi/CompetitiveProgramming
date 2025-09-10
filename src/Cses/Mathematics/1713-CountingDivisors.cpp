#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;

  vector<int> v(1e6+5);
  for(int i = 2; i < 1e6+5; i++) for(int j = i; j < 1e6+5; j += i) v[j]++;

  while(n--){
    int x; cin >> x;
    cout << v[x]+1 << '\n';
  }
}
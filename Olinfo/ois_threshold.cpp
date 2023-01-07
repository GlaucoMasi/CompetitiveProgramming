#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(101, 0);

  int a;
  while(cin >> a) v[a]++;

  int curr = 0;
  for(int i = 100; i >= 0; i--){
    curr += v[i];
    cout << curr << " ";
  }
}
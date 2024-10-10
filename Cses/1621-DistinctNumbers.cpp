#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;

  int num = 0;
  map<int, bool> m;

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    if(!m.count(a)){
      m[a] = 1;
      num++;
    } 
  }

  cout << num;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v = {0, 25, 18, 15, 12, 10, 8, 6, 4, 2, 1};
  int t; cin >> t;
  while(t--){
    int n; cin >> n;
    int t1 = 0, t2 = 0;

    for(int i = 0; i < n; i++){
      int a; cin >> a;
      
      if(a <= 10) t1 += v[a];

      if(a == 1) t2 += v[2];
      else t2 += v[1];
    }

    if(t1 >= t2) cout << "Champion\n";
    else cout << "Practice harder\n";
  }
}
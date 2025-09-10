#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<long long> v(2, 0);
  set<int> a;

  for(int i = 0; i < n; i++){
    int t; cin >> t;
    if(a.count(t)){
      if(v[0] < t){
        v[1] = v[0];
        v[0] = t;
      }else if(v[1] < t) v[1] = t;

      a.erase(t);
    }else a.insert(t);
  }

  cout << v[0]*v[1];
}
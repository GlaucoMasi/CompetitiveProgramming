#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(n); for(auto &i : v) cin >> i;

  for(int i = 1; i <= 6; i++){
    int pos = 0, throws = 0;

    while(pos <= n-1){
      throws++;
      pos += i;

      while(pos <= n-1 && v[pos]) pos += v[pos];
    }

    cout << throws << " ";
  }
}
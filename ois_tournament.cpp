#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(n);

  int big_left, big_right, small_left, small_right;
  big_right = big_left = -1e9;
  small_right = small_left = 1e9;


  for(int i = 0; i < n; i++){
    cin >> v[i];

    big_right = max(big_right, v[i]+i);
    big_left = max(big_left, v[i]-i);
    small_right = min(small_right, -v[i]+i);
    small_left = min(small_left, -v[i]-i);
  }

  int best = 0;
  for(int i = 0; i < n; i++){
    best = max(best, big_right-v[i]-i);
    best = max(best, big_left-v[i]+i);
    best = max(best, small_right+v[i]-i);
    best = max(best, small_left+v[i]+i);
  }

  cout << best;
}
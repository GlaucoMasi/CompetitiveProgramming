#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x; cin >> n >> x;
  vector<int> h(n), s(n);
  for(auto &i : h) cin >> i;
  for(auto &i : s) cin >> i;

  vector<int> best(x+1, 0);
  for(int i = 0; i < n; i++){
    int price = h[i], pages = s[i];

    for(int j = x+1; j >= 0; j--){
      if(j - price < 0) continue;

      best[j] = max(best[j], best[j-price] + pages);
    } 
  }

  cout << best[x];
}
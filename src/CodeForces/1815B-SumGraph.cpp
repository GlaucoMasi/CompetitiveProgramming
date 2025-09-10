#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt; cin >> tt;

  while(tt--){
    int n; cin >> n; int t;
    cout << "+ " << n+1 << endl; cin >> t;
    cout << "+ " << n+2 << endl; cin >> t;

    pair<int, int> dist = {-1, -1};
    for(int i = 2; i <= n; i++){
      cout << "? 1 " << i << endl;
      int d; cin >> d;
      dist = max(dist, {d, i});
    }

    vector<int> ans1(n+1), ans2(n+1);
    ans1[dist.second] = 1; ans2[dist.second] = n/2+1;

    for(int i = 1; i <= n; i++){
      if(i == dist.second) continue;

      cout << "? " << dist.second << " " << i << endl;
      int a; cin >> a;

      // il piu lontano è l'1
      if(a%2) ans1[i] = n-a/2;
      else ans1[i] = a/2+1;

      // è n/2+1
      if(a%2) ans2[i] = n/2+1 - a/2 - 1;
      else ans2[i] = n/2+1 + a/2;
    }

    int idx;
    for(idx = 1; idx <= n; idx++) if(ans1[idx] == n/2+1) break;
    if(ans2[idx] != 1) for(int i = 1; i <= n; i++) ans2[i] = n-ans2[i]+1;

    cout << "!";
    for(int i = 1; i <= n; i++) cout << " " << ans1[i];
    for(int i = 1; i <= n; i++) cout << " " << ans2[i];
    cout << endl; cin >> t;
  }
}
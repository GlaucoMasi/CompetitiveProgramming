#include <bits/stdc++.h>
using namespace std;

void solve() {
  int n; cin >> n;
  vector<int> start(9);

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    start[a-1]++;
  }

  cout << "- 0" << '\n'; cout.flush();

  vector<int> then(9, 0); vector<int> types(n);
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    then[a-1]++;
    types[i] = a-1;
  }

  int type = -1;
  for(int i = 0; i < 9; i++) if(start[i] < then[i]) type = i;

  if(type == -1){
    cout << "- 0" << '\n'; cout.flush();

    then.clear(); then.resize(9, 0);
    for(int i = 0; i < n; i++){
      int a; cin >> a;
      then[a-1]++;
      types[i] = a-1;
    }

    for(int i = 0; i < 9; i++) if(start[i] < then[i]) type = i;
  }

  cout << "- " << n-then[type] << " ";
  for(int i = 0; i < n; i++) if(types[i] != type) cout << i+1 << " ";
  cout << '\n';
  cout.flush();
  n = then[type];

  int ans = -1;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    if(a-1 != type) ans = i+1;
  }

  if(ans == -1){
    cout << "- 0" << '\n'; cout.flush();

    for(int i = 0; i < n; i++){
      int a; cin >> a;
      if(a-1 != type) ans = i+1;
    }
  }

  cout << "! " << ans << '\n';
  cout.flush();
}

int main() {
  int t; cin >> t;
  while(t--) solve();
}
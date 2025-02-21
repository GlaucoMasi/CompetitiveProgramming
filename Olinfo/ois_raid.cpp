#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, p; cin >> n >> p;
  vector<int> h(n); for(auto &i : h) cin >> i;

  vector<int> down(n, 1e9);
  auto check = [&](int i){
    return ((!i || h[i] > h[i-1]) && (i == n-1 || h[i] > h[i+1]));
  };

  for(int start = 0; start < n; start++) if(check(start)){
    down[start] = 0;
    for(int i = 1; i < p && start+i < n && down[start+i-1] != 1e9; i++) if(start+i == n-1 || h[start+i] > h[start+i+1]) down[start+i] = i;
    
    int i = start-1;
    for(int j = 1; j < p && i >= 0 && down[i+1] != 1e9; i--, j++){
      if(down[i] != 1e9) break;
      if(i == 0 || h[i] > h[i-1] || down[i-1] < j) down[i] = j;
      else if(down[i-1] >= j){
        if(down[i-1] < p-1){
          down[i] = down[i-1]+1;
          j = down[i-1]+1;
        }
      }
    }
  }

  int ans = 0;
  for(auto i : down) ans += (i != 1e9);
  cout << ans;
}
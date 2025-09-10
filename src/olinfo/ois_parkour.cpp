#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, m; cin >> n >> m;
  if(n > m) cout << -1;
  else{
    for(int i = 0; i < n; i++){
      for(int j = 0; j < m; j++){
        if(j == i-1) cout << '#';
        else cout << '.';
      }

      cout << '\n';
    }
  }
}
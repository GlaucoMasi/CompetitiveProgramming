#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> v(n); for(auto &i : v) cin >> i;

  int idx = 0;
  for(int i = 0; i < n; i++) if(v[(i+1)%n] != 1 && v[(i+1)%n] != v[i]+1){
    cout << -1;
    return 0;
  }else if(v[i] == 1) idx = i;

  cout << (n-idx)%n;
}
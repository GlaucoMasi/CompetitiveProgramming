#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; cin >> n;
  vector<int> idx(n);

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    idx[--a] = i;
  }

  int ans = 1;
  for(int i = 0; i < n-1; i++) ans += (idx[i] > idx[i+1]);
  cout << ans;
}
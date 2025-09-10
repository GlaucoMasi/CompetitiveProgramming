#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, m, k; fin >> n >> m >> k;
  vector<int> v(n+2);
  v[0] = 0, v[n+1] = k;
  for(int i = 1; i <= n; i++) fin >> v[i];
  n += 2;

  int ans = -1;
  for(int i = 0; i < n-1; i++){
    ans++;
    int j = i;
    while(j+1 < n && v[j+1]-v[i] <= m) j++;
    i = j-1;
  }

  fout << ans;
}
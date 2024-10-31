#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, m; cin >> n >> m;
  vector<int> idx(n), v(n);

  for(int i = 0; i < n; i++){
    cin >> v[i];
    idx[--v[i]] = i;
  }

  int ans = 1;
  for(int i = 0; i < n-1; i++) ans += (idx[i] > idx[i+1]);
  
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    a = v[--a], b = v[--b];
    if(a > b) swap(a, b);
    
    if(a) ans += (idx[b] < idx[a-1]) - (idx[a] < idx[a-1]);
    if(a != b-1 && b) ans += (idx[a] < idx[b-1]) - (idx[b] < idx[b-1]);
    if(a != b-1 && a != n-1) ans += (idx[b] > idx[a+1]) - (idx[a] > idx[a+1]);
    if(b != n-1) ans += (idx[a] > idx[b+1]) - (idx[b] > idx[b+1]);
    if(a == b-1) ans += (idx[a] < idx[b] ? 1 : -1);
    
    swap(idx[a], idx[b]);
    swap(v[idx[a]], v[idx[b]]);
    cout << ans << '\n';
  }
}
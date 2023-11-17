#include <bits/stdc++.h>
using namespace std;

int comps;
vector<int> fat, sz;

int get(int i){
  if(i == fat[i]) return i;
  else return fat[i] = get(fat[i]);
}

void merge(int a, int b){
  a = get(a), b = get(b);
  if(a == b) return;
  
  if(sz[a] < sz[b]) swap(a, b);
  fat[b] = a;
  sz[a] += sz[b];
  comps--;
}

int main() {
  int r, c, n; cin >> r >> c >> n;
  fat.resize(n); iota(fat.begin(), fat.end(), 0);
  sz.resize(n, 1);
  comps = n;

  map<int, int> row, col, diag1, diag2;

  for(int i = 0; i < n; i++){
    int x, y; cin >> x >> y;
    if(row.count(x)) merge(i, row[x]);
    else row[x] = i;

    if(col.count(y)) merge(i, col[y]);
    else col[y] = i;

    if(diag1.count(x-y)) merge(i, diag1[x-y]);
    else diag1[x-y] = i;

    if(diag2.count(x+y)) merge(i, diag2[x+y]);
    else diag2[x+y] = i;
  }

  int mod = 1e9+7;
  long long ans = 1;
  while(comps--) ans = (ans*2)%mod;
  cout << ans;
}
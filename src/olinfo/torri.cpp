#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> v(2048, 0);

void upd(int i, int k){
  int u = 1024 + i;
  
  if(v[u] > k) return;
  v[u] = k;

  while(u > 1){
    u /= 2;
    v[u] = max(v[2*u], v[2*u+1]);
  }
}

int get(int u, int l, int r, int x, int y){
  if(l >= y || r <= x) return 0;
  if(l >= x && r <= y) return v[u];

  return max(get(2*u, l, l + (r-l)/2, x, y), get(2*u+1, l + (r-l)/2, r, x, y));
}

int main() {
  int n; fin >> n;
  vector<pair<int, int>> v(n);

  int tot = 0;
  for(auto &[a, b] : v){
    fin >> a >> b;
    tot += b;
  }

  int ans = -1e9;
  for(int i = 0; i < n; i++){
    int curr = v[i].second + get(1, 0, 1024, v[i].first+1, 1000);
    ans = max(ans, curr);
    upd(v[i].first, curr);
  }

  fout << tot-ans;
}
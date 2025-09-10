#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, q;
vector<vector<int>> v;
vector<int> depth;

int main() {
  cin >> n >> q;
  v.resize(n, vector<int>(log2(4*n)));
  depth.resize(n);

  v[0] = {-1};
  depth[0] = 0;
  for(int i = 1; i < n; i++){
    cin >> v[i][0];
    v[i][0]--;
    depth[i] = depth[v[i][0]]+1;

    for(int j = 1; j < log2(2*n); j++){
      v[i][j] = v[i][j-1] == -1 ? v[i][j-1] : v[v[i][j-1]][j-1];
    }
  }

  int a, b;
  while(q--){
    cin >> a >> b;
    a--; b--;

    if(depth[a] > depth[b]) swap(a, b);

    int k = depth[b]-depth[a];
    for(int j = 0; j < log2(2*n); j++){
      if(k & (1<<j)) b = v[b][j];
    }

    if(a == b){
      cout << a+1 << '\n';
      continue;
    }

    for(int j = log2(2*n); j >= 0; j--){
      if(v[a][j] != v[b][j]){
        a = v[a][j];
        b = v[b][j];
      }
    }

    cout << v[a][0]+1 << '\n';
  }
}
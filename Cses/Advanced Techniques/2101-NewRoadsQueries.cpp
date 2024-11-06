#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, q, k = 25;
vector<int> sz, anc, depth;
vector<vector<int>> fat, ans;
vector<vector<pair<int, int>>> g;

int get(int i){
  if(anc[i] == i) return i;
  return anc[i] = get(anc[i]);
}

bool join(int a, int b){
  a = get(a), b = get(b);
  if(a == b) return 0;
  if(sz[b] > sz[a]) swap(a, b);
  sz[a] += sz[b];
  anc[b] = a;
  return 1;
}

void f(int i, int p){
  if(p != -1){
    for(int j = 1; j < k; j++){
      if(fat[i][j-1] == -1) break;
      fat[i][j] = fat[fat[i][j-1]][j-1];
      ans[i][j] = max(ans[i][j-1], ans[fat[i][j-1]][j-1]);
    }
  }

  for(auto [j, l] : g[i]){
    if(j == p) continue;
    depth[j] = depth[i]+1;
    fat[j][0] = i;
    ans[j][0] = l;
    f(j, i);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m >> q;
  ans.resize(n, vector<int>(k));
  fat.resize(n, vector<int>(k, -1));
  sz.resize(n, 1);
  depth.resize(n);
  g.resize(n);

  anc.resize(n);
  iota(anc.begin(), anc.end(), 0);

  for(int i = 1; i <= m; i++){
    int a, b; cin >> a >> b; a--; b--;
    if(join(a, b)){
      g[a].push_back({b, i});
      g[b].push_back({a, i});
    }
  }

  for(int i = 0; i < n; i++){
    if(!depth[i]){
      depth[i] = 1;
      f(i, -1);
    }
  }

  for(int i = 0; i < q; i++){
    int a, b; cin >> a >> b; a--; b--;

    if(get(a) != get(b)) cout << "-1\n";
    else{
      int tot = 0;
      if(depth[a] > depth[b]) swap(a, b);
      
      int t = depth[b]-depth[a];
      for(int i = 0; i < k; i++) if(t&(1<<i)){
        tot = max(tot, ans[b][i]);
        b = fat[b][i];
      }

      if(a != b){
        for(int i = k-1; i >= 0; i--) if(fat[a][i] != fat[b][i]){
          tot = max({tot, ans[a][i], ans[b][i]});
          a = fat[a][i]; b = fat[b][i];
        }

        tot = max({tot, ans[a][0], ans[b][0]});
      }

      cout << tot << '\n';
    }
  }
}

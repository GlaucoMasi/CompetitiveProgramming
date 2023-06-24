#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<vector<pair<int, int>>> g;

vector<int> sz, anc;

int get(int i){
  if(i == anc[i]) return i;
  else return anc[i] = get(anc[i]);
}

bool join(int a, int b){
  a = get(a), b = get(b);

  if(a == b) return 0;

  if(sz[a] < sz[b]) swap(a, b);

  anc[b] = a;
  sz[a] += sz[b];
  return 1;
}

int LOG;
vector<vector<int>> fat, magg;
vector<int> depth;

int longest(int a, int b){
  int ans = 0;

  int k = depth[b]-depth[a];
  for(int j = 0; j <= LOG; j++){
    if(k & (1<<j)){
      ans = max(ans, magg[b][j]);
      b = fat[b][j];
    }
  }

  if(a == b) return ans;

  for(int j = LOG; j >= 0; j--){
    if(fat[a][j] != fat[b][j]){
      ans = max(ans, max(magg[a][j], magg[b][j]));
      a = fat[a][j], b = fat[b][j];
    }
  }

  ans = max(ans, max(magg[a][0], magg[b][0]));
  return ans;
}

void dfs(int i, int p){
  for(int j = 1; j <= LOG; j++){
    if(fat[i][j-1] != -1){
      fat[i][j] = fat[fat[i][j-1]][j-1];
      magg[i][j] = max(magg[i][j-1], magg[fat[i][j-1]][j-1]);
    }
  }

  for(auto j : g[i]){
    if(j.first == p) continue;

    depth[j.first] = depth[i]+1;
    fat[j.first][0] = i;
    magg[j.first][0] = j.second;
    dfs(j.first, i); 
  }
}

int main() {
  cin >> n >> s;
  g.resize(s);

  sz.resize(s, 1);
  anc.resize(s); iota(anc.begin(), anc.end(), 0);

  LOG = log2(s);
  fat.resize(s, vector<int>(LOG+1, -1));
  magg.resize(s, vector<int>(LOG+1, 0));
  depth.resize(s); depth[0] = 1;

  vector<pair<pair<int, int>, int>> movies;
  vector<pair<int, pair<int, int>>> kruskal;

  for(int i = 0; i < n; i++){
    int a, b, c; cin >> a >> b >> c;
    movies.push_back({{a, b}, c});
    kruskal.push_back({c, {a, b}});
  }

  sort(kruskal.begin(), kruskal.end());

  long long mst = 0;
  for(auto temp : kruskal){
    auto [a, b] = temp.second;
    int t = temp.first;

    if(join(a, b)){
      mst += t;
      g[a].push_back({b, t});
      g[b].push_back({a, t});
    }
  }

  dfs(0, -1);
  
  for(auto movie : movies){
    auto [a, b] = movie.first;
    int t = movie.second;

    if(depth[a] > depth[b]) swap(a, b);

    if(fat[b][0] == a && magg[b][0] == t) cout << mst << '\n';
    else cout << mst + t - longest(a, b) << '\n';
  }
}
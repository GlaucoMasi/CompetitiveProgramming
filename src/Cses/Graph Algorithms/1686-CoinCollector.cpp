#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
vector<vector<int>> g, inv;
vector<int> v, ord, col;
vector<bool> vis;

vector<long long> val;
vector<vector<int>> cg;
vector<vector<int>> comps;

vector<int> topo;

void f(int i, vector<vector<int>> &g, vector<int> &ord){
  vis[i] = 1;
  for(auto j : g[i]) if(!vis[j]) f(j, g, ord);
  ord.push_back(i);
}

void cond(int i, int idx){
  vis[i] = 0; col[i] = idx;
  comps.back().push_back(i);
  for(auto j : inv[i]) if(vis[j]) cond(j, idx);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m;
  g.resize(n);
  v.resize(n);
  inv.resize(n);
  vis.resize(n);
  col.resize(n);
  for(auto &i : v) cin >> i;

  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    inv[b].push_back(a);
  }

  for(int i = 0; i < n; i++) if(!vis[i]) f(i, g, ord);

  int t = 0;
  for(int i = n-1; i >= 0; i--) if(vis[ord[i]]){
    comps.push_back({});
    cond(ord[i], t++);
  }

  cg.resize(t);
  val.resize(t);
  for(auto scc : comps){
    unordered_set<int> reach;
    for(auto j : scc){
      val[col[j]] += v[j];
      for(auto k : g[j]) if(col[j] != col[k]) reach.insert(col[k]);
    }

    for(auto i : reach) cg[col[scc[0]]].push_back(i);
  }

  for(int i = 0; i < t; i++) if(!vis[i]) f(i, cg, topo);
  for(int i = t-1; i >= 0; i--){
    int node = topo[i];
    long long best = 0;
    for(auto j : cg[i]) best = max(best, val[j]);
    val[i] += best;
  }

  cout << *max_element(val.begin(), val.end());
}
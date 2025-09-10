#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct mass{
  long long prefix, suffix, best, sum;

  void create(const mass &l, const mass &r){
    sum = l.sum + r.sum;
    prefix = max(l.prefix, l.sum + r.prefix);
    suffix = max(l.suffix + r.sum, r.suffix);
    best = max(max(max(l.best, r.best), max(prefix, suffix)), l.suffix + r.prefix);
  }

  void set(int k){
    sum = k;
    prefix = suffix = best = k != -1 ? max(k, 0) : -1;
  }
};

int l;
int n, t;
vector<vector<pair<int, int>>> g;
vector<vector<int>> father;
vector<vector<long long>> ans;
vector<vector<mass>> str;
vector<int> depth;

void dfs(int u, int fat, int arco){
  if(u != 0){
    depth[u] = depth[fat]+1;
    father[u][0] = fat;

    if(t == 1 || t == 2) ans[u][0] = arco; 
    if(t == 3) str[u][0].set(arco);

    for(int j = 1; j < l; j++){
      father[u][j] = father[u][j-1] == -1 ? -1 : father[father[u][j-1]][j-1];

      if(t != 0){
        if(father[u][j] != -1){
          if(t == 1) ans[u][j] = ans[u][j-1] + ans[father[u][j-1]][j-1];
          if(t == 2) ans[u][j] = min(ans[u][j-1], ans[father[u][j-1]][j-1]);
          if(t == 3) str[u][j].create(str[u][j-1], str[father[u][j-1]][j-1]);
        }else{
          if(t != 3) ans[u][j] = -1;
          else str[u][j].set(-1);
        }
      }
    }
  }

  for(auto i : g[u]) 
    if(depth[i.first] == -1) dfs(i.first, u, i.second);
}

void inizia(int N, int T, int A[], int B[], int C[]){
  n = N; t = T;
  l = log2(n);
  g.resize(n);

  father.resize(n, vector<int>(l+1));
  if(t == 1 || t == 2) ans.resize(n, vector<long long>(l+1));
  if(t == 3) str.resize(n, vector<mass>(l+1));
  depth.resize(n, -1);

  for(int i = 0; i < n-1; i++){ 
    g[A[i]].push_back({B[i], C[i]});
    g[B[i]].push_back({A[i], C[i]});
  }

  for(auto &i : father[0]) i = -1;

  depth[0] = 1;
  dfs(0, -1, -1);
}

int lca(int u, int v){
  if(depth[u] < depth[v]) swap(u, v);

  int k = depth[u]-depth[v];
  for(int j = 0; j < l; j++){
    if(k & (1<<j)) u = father[u][j];
  }

  if(u == v) return u;

  for(int j = l; j >= 0; j--){
    if(father[u][j] != father[v][j]){
      u = father[u][j];
      v = father[v][j];
    }
  }

  return father[u][0];
}

long long distanza1(int u, int v){
  int k = lca(u, v);

  return depth[u]+depth[v]-2*depth[k];
}

vector<long long> calc(int u, int v){
  if(u == v){
    if(t == 1) return {0};
    if(t == 2) return {1000000000000000000};
    if(t == 3) return {0, 0, 0, 0};
  }

  int d = depth[u]-depth[v];

  long long sum = 0, pref = 0, suff = 0, res = 0;
  if(t == 2) res = 1e18;

  for(int j = 0; j < l; j++){
    if(d & (1<<j)){
      if(t == 1) res += ans[u][j];
      if(t == 2) res = min(res, ans[u][j]);
      if(t == 3){
        long long temp_sum = sum;
        sum += str[u][j].sum;

        long long temp_pref = pref;
        pref = max(pref, temp_sum + str[u][j].prefix);
        
        long long temp_suff = suff;
        suff = max(suff + str[u][j].sum, str[u][j].suffix);

        res = max(max(max(res, str[u][j].best), max(pref, suff)), temp_suff + str[u][j].prefix);
      }
      
      u = father[u][j];
    }
  }

  if(t == 3) return {sum, pref, suff, res};
  else return {res};
}

long long distanza2(int u, int v){
  int k = lca(u, v);

  return calc(u, k)[0] + calc(v, k)[0];
}

long long minimo(int u, int v){
  int k = lca(u, v);

  return min(calc(u, k)[0], calc(v, k)[0]);
}

long long massimo(int u, int v){
  int k = lca(u, v);

  auto uno = calc(u, k), due = calc(v, k);

  long long ans = max(uno[3], due[3]);
  ans = max(ans, max(uno[1], due[1]));
  ans = max(ans, uno[2]+due[2]);
  ans = max(ans, max(uno[0]+due[2], due[0]+uno[2]));
  return ans;
}
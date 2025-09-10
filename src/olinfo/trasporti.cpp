#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int l;
vector<vector<int>> g, v, memo;
vector<int> depth;

void dfs(int u, int father, int *briganti){
  if(u != 0){
    depth[u] = depth[father]+1;
    v[u][0] = father;
    memo[u][0] = max(briganti[u], briganti[father]);

    for(int j = 1; j < l; j++){
      v[u][j] = v[u][j-1] == -1 ? -1 : v[v[u][j-1]][j-1];

      if(v[u][j] == -1){
        v[u][j] = -1;
        memo[u][j] = -1;
      }else{
        v[u][j] = v[v[u][j-1]][j-1];
        memo[u][j] = max(memo[u][j-1], memo[v[u][j-1]][j-1]);
      }
    }
  }

  for(auto i : g[u]){
    if(depth[i] == -1) dfs(i, u, briganti);
  }
}

void solve(int N, int Q, int *briganti, int *A, int *B, int *start, int *end, int *sol){
  l = log2(2*N);
  g.resize(N);
  depth.resize(N, -1);
  v.resize(N, vector<int>(l+1, -1));
  memo.resize(N, vector<int>(l+1, -1));
  for(int i = 0; i < N-1; i++){
    g[A[i]].push_back(B[i]);
    g[B[i]].push_back(A[i]);
  }

  depth[0] = 1;
  dfs(0, -1, briganti);

  int a, b;
  for(int i = 0; i < Q; i++){
    a = start[i], b = end[i];
    
    if(depth[a] < depth[b]) swap(a, b);

    int ans_a = briganti[a], ans_b = briganti[b];

    int k = depth[a]-depth[b];
    for(int j = 0; j < l; j++){
      if(k & 1<<j){
        ans_a = max(ans_a, memo[a][j]);
        a = v[a][j];
      }
    }

    if(a == b){
      sol[i] = max(ans_a, ans_b);
      continue;
    }

    for(int j = l; j >= 0; j--){
      if(v[a][j] != v[b][j]){
        ans_a = max(ans_a, memo[a][j]);
        ans_b = max(ans_b, memo[b][j]);

        a = v[a][j];
        b = v[b][j];
      }
    }

    ans_a = max(ans_a, memo[a][0]);
    ans_b = max(ans_b, memo[b][0]);
    sol[i] = max(ans_a, ans_b);
  }

  return;
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int mod = 1e9+7;
int n, m, k;
vector<vector<int>> s;
vector<vector<pair<int, int>>> memo;

void calc(int* X, int* Y){
  queue<pair<pair<int, int>, int>> q;
  for(int i = 0; i < k; i++) q.push({{X[i], Y[i]}, 0});

  while(!q.empty()){
    auto curr = q.front(); q.pop();
    if(memo[curr.first.first][curr.first.second].first != -1) continue;
    memo[curr.first.first][curr.first.second].first = curr.second;

    for(int i = -1; i < 2; i++){
      for(int j = -1; j < 2; j++){
        if(abs(i) == abs(j)) continue;

        if(curr.first.first+i < n && curr.first.first+i >= 0 && curr.first.second+j < m && curr.first.second+j >= 0)
          q.push({{curr.first.first+i, curr.first.second+j}, curr.second+1});
      }
    }
  }
}

int ContaPercorsi(int N, int M, int K, int* X, int* Y){
  n = N, m = M, k = K;
  memo.resize(n, vector<pair<int, int>>(m, {-1, -1}));

  calc(X, Y);

  memo[0][0].second = memo[0][0].first;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(i == 0 && j == 0) continue;

      if(i > 0) memo[i][j].second = max(memo[i][j].second, memo[i-1][j].second);
      if(j > 0) memo[i][j].second = max(memo[i][j].second, memo[i][j-1].second);

      memo[i][j].second = min(memo[i][j].first, memo[i][j].second);

      
    }
  }

  int sic = memo[n-1][m-1].second;
  memo[0][0].second = 1;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      if(i == 0 && j == 0) continue;

      memo[i][j].second = 0;

      if(i > 0 && memo[i-1][j].first >= sic) memo[i][j].second = (memo[i][j].second + memo[i-1][j].second) % mod;
      if(j > 0 && memo[i][j-1].first >= sic) memo[i][j].second = (memo[i][j].second + memo[i][j-1].second) % mod;
  
      if(memo[i][j].first < sic) memo[i][j].second = 0;
    }
  }

  return memo[n-1][m-1].second;
}
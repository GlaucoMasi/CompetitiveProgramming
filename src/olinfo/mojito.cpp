#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, xs, ys, g;
vector<vector<bool>> memo;
vector<vector<pair<int, int>>> mat;

pair<int, int> find(int x, int y) {
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
  q.push({0, {x, y}});
  vector<vector<bool>> vis(n, vector<bool>(m, 0));
  
  while(!q.empty()){
    int d = q.top().first;
    auto curr = q.top().second; 
    q.pop();
    
    if(curr.first < 0 || curr.first > n-1 || curr.second < 0 || curr.second > m-1) continue;

    if(vis[curr.first][curr.second]) continue;
    vis[curr.first][curr.second] = 1;
  
    auto sq = mat[curr.first][curr.second];
    if(sq.first != -1 && sq.second != -1) return sq;

    q.push({d+1, {curr.first-1, curr.second}});
    q.push({d+1, {curr.first, curr.second-1}});
    q.push({d+1, {curr.first+1, curr.second}});
    q.push({d+1, {curr.first, curr.second+1}});
  }

  return {-1, -1};
}

int main() {
  fin >> n >> m >> xs >> ys >> g;
  xs--; ys--;
  memo.resize(n, vector<bool>(m, 0));
  mat.resize(n, vector<pair<int, int>>(m, {-1, -1}));

  for(int i = 0; i < g; i++){
    int a, b, c, d;
    fin >> a >> b >> c >> d;
    a--; b--; c--; d--;
    mat[a][b] = {c, d};
  }

  int x, y;
  int conto = -1;
  x = xs; y = ys;
  while(!memo[x][y]){
    memo[x][y] = 1;
    conto++;

    auto a = find(x, y);
    if(a.first == -1 && a.second == -1) break;
    x = a.first; y = a.second;
  }

  fout << conto;
}
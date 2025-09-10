#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

using type = pair<int, pair<int, int>>;

int n, m;
int ans = 0;
vector<vector<pair<int, int>>> g;
vector<unordered_map<int, int>> memo;

int f(int start, int vel) {
  if(memo[start].count(vel) != 0) return memo[start][vel];

  int best = 0;
  for(auto i : g[start]){
    if(vel < i.second){
      int temp = f(i.first, i.second) + 1;
      best = max(best, temp);
    }
  }

  ans = max(ans, best);
  return memo[start][vel] = best;
}

int main() {
  fin >> n >> m;

  g.resize(n);
  memo.resize(n);

  for (int i = 0; i < m; i++) {
    int a, b, c;
    fin >> a >> b >> c;

    g[a].push_back({b, c});
  }

  for(int i = 0; i < n; i++) f(i, 0);

  fout << ans;
}
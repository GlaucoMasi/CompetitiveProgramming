#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, q; cin >> n >> q;
  vector<int> v(n); for(auto &i : v) cin >> i;

  vector<vector<int>> dist(20, vector<int>(20, 1e9));
  for(int i = 0; i < 20; i++) dist[i][i] = 0;

  for(auto i : v){
    for(int x = 0; x < 20; x++) for(int y = x+1; y < 20; y++){
      if(!(i&(1<<x)) || !(i&(1<<y))) continue;
      dist[x][y] = dist[y][x] = 1;
    }
  }

  for(int k = 0; k < 20; k++){
    for(int i = 0; i < 20; i++){
      for(int j = i+1; j < 20; j++){
        dist[i][j] = dist[j][i] = min(dist[i][j], dist[i][k]+dist[k][j]);
      }
    }
  }

  while(q--){
    int best = 1e9;
    int a, b; cin >> a >> b;

    for(int x = 0; x < 20; x++) for(int y = 0; y < 20; y++){
      if(!(v[a-1]&(1<<x)) || !(v[b-1]&(1<<y))) continue;
      best = min(best, dist[x][y]);
    }

    cout << (best != 1e9 ? best+1 : -1) << '\n';
  }
}
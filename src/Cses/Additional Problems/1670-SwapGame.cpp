#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> p(10, 1);

int move(int g, int i, int j){
  int a = (g%p[i+1])/p[i], b = (g%p[j+1])/p[j];
  g -= a*p[i]+b*p[j];
  g += a*p[j]+b*p[i];
  return g;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  for(int i = 1; i <= 9; i++) p[i] = p[i-1]*9;

  int grid = 0, done = 0;
  for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++){
    int a; cin >> a; a--;
    grid += a*p[3*i+j];
    done += (3*i+j)*p[3*i+j];
  }
  
  vector<bool> vis(p[9]);
  queue<pair<int, int>> q;
  vis[grid] = 1; q.push({grid, 0});
  while(1){
    auto [g, d] = q.front(); q.pop();

    if(g == done){
      cout << d;
      break;
    }

    for(int i = 0; i < 8; i++){
      if(i%3 == 2) continue;
      int nxt = move(g, i, i+1);
      if(!vis[nxt]){
        vis[nxt] = 1;
        q.push({nxt, d+1});
      }
    }

    for(int i = 0; i < 6; i++){
      int nxt = move(g, i, i+3);
      if(!vis[nxt]){
        vis[nxt] = 1;
        q.push({nxt, d+1});
      }
    }
  }
}
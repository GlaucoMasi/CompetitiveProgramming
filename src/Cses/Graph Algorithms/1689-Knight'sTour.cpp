#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int ans[8][8], poss[8][8];
vector<pair<int, int>> moves = {
  {1, 2},
  {2, 1},
  {-1, 2},
  {2, -1},
  {1, -2},
  {-2, 1},
  {-1, -2},
  {-2, -1}
};

void print(){
  for(int i = 0; i < 8; i++){
    for(int j = 0; j < 8; j++) cout << ans[i][j] << " ";
    cout << '\n';
  }

  exit(0);
}

bool valid(int x, int y){
  return (x >= 0 && y >= 0 && x < 8 && y < 8);
}

void f(int x, int y, int idx){
  ans[x][y] = idx;
  if(idx == 64) print();

  vector<array<int, 3>> opt;
  for(auto [a, b] : moves) if(valid(x+a, y+b) && !ans[x+a][y+b]) opt.push_back({poss[x+a][y+b], x+a, y+b});

  sort(opt.begin(), opt.end());
  for(auto [t, a, b] : opt){
    poss[a][b]--;
    f(a, b, idx+1);
    poss[a][b]++;
  }

  ans[x][y] = 0;
}

int main() {
  //ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int x, y; cin >> x >> y;
  x--; y--; swap(x, y);

  for(int i = 0; i < 8; i++) for(int j = 0; j < 8; j++) for(auto [a, b] : moves) poss[i][j] += valid(i+a, j+b);
  f(x, y, 1);
}
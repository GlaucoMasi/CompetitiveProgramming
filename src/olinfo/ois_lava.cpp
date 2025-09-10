#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int h, w;
  fin >> h >> w;
  vector<vector<bool>> v(h, vector<bool>(w, 0));
  vector<vector<long long>> d(h, vector<long long>(w, 1e18));

  char c;
  for(int i = 0; i < h; i++){
    for(int j = 0; j < w; j++){
      fin >> c;
      if(c == '#') v[i][j] = 1;
    }
  }

  priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> q;
  d[0][0] = 0;
  q.push({0, {0, 0}});
  while(!q.empty()){
    long long dist = q.top().first;
    int x = q.top().second.first, y = q.top().second.second;
    q.pop();

    if(x == h-1 && y == w-1) break;
    v[x][y] = 1;

    if(x+2 < h){
      if(!v[x+2][y] && d[x+2][y] > dist + 1){
        d[x+2][y] = dist + 1;
        q.push({d[x+2][y], {x+2, y}});
      }
    }

    if(x+1 < h){
      if(!v[x+1][y] && d[x+1][y] > dist + 1){
        d[x+1][y] = dist + 1;
        q.push({d[x+1][y], {x+1, y}});
      }
    }
    
    if(x-2 >= 0){
      if(!v[x-2][y] && d[x-2][y] > dist + 1){
        d[x-2][y] = dist + 1;
        q.push({d[x-2][y], {x-2, y}});
      }
    }

    if(x-1 >= 0){
      if(!v[x-1][y] && d[x-1][y] > dist + 1){
        d[x-1][y] = dist + 1;
        q.push({d[x-1][y], {x-1, y}});
      }
    }

    if(y+2 < w){
      if(!v[x][y+2] && d[x][y+2] > dist + 1){
        d[x][y+2] = dist + 1;
        q.push({d[x][y+2], {x, y+2}});
      }
    }
    
    if(y+1 < w){
      if(!v[x][y+1] && d[x][y+1] > dist + 1){
        d[x][y+1] = dist + 1;
        q.push({d[x][y+1], {x, y+1}});
      }
    }

    if(y-2 >= 0){
      if(!v[x][y-2] && d[x][y-2] > dist + 1){
        d[x][y-2] = dist + 1;
        q.push({d[x][y-2], {x, y-2}});
      }
    }

    if(y-1 >= 0){
      if(!v[x][y-1] && d[x][y-1] > dist + 1){
        d[x][y-1] = dist + 1;
        q.push({d[x][y-1], {x, y-1}});
      }
    }

    if(x+1 < h && y+1 < w){
      if(!v[x+1][y+1] && d[x+1][y+1] > dist + 1){
        d[x+1][y+1] = dist + 1;
        q.push({d[x+1][y+1], {x+1, y+1}});
      }
    }

    if(x-1 >= 0  && y+1 < w){
      if(!v[x-1][y+1] && d[x-1][y+1] > dist + 1){
        d[x-1][y+1] = dist + 1;
        q.push({d[x-1][y+1], {x-1, y+1}});
      }
    }

    if(x+1 < h && y-1 >= 0){
      if(!v[x+1][y-1] && d[x+1][y-1] > dist + 1){
        d[x+1][y-1] = dist + 1;
        q.push({d[x+1][y-1], {x+1, y-1}});
      }
    }

    if(x-1 >= 0 && y-1 >= 0){
      if(!v[x-1][y-1] && d[x-1][y-1] > dist + 1){
        d[x-1][y-1] = dist + 1;
        q.push({d[x-1][y-1], {x-1, y-1}});
      }
    }
  }

  fout << d[h-1][w-1];
}
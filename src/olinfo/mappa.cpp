#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int INF = 1e9;
using type = pair<int, int>;

vector<vector<bool>> v;
int n;

vector<int> drig = {0, 1, 0, -1};
vector<int> dcol = {1, 0, -1, 0};

int main() {
  fin >> n;
  v.resize(n+1, vector<bool> (n+1));

  for(int i = 0; i < n; i++)
    for(int j = 0; j < n; j++){
      char c;
      fin >> c;
      v[i][j] = (c == '+') ? false : true;
    }

  priority_queue<type, vector<type>, greater<type>> pq;
  vector<vector<int>> d(n + 5, vector<int> (n+5, INF));
  
  pq.push({0, 0});
  d[0][0] = 0;

  while(!pq.empty()){
    int x = pq.top().first;
    int y = pq.top().second;
    pq.pop();
  
    for(int i = -1; i < 2; i ++){
      for(int j = -1; j < 2; j++){
        int rig = x + i;
        int col = y + j;
        if(rig == 0 && col == 0) continue;
        if(rig >= 0 && col >= 0 && rig < n && col < n){
          if(v[rig][col] && v[x][y]){
            if(d[rig][col] > d[x][y]+1){
              d[rig][col] = d[x][y]+1;
              pq.push({rig, col});
            }
          }
        }
      }
    }
  }

  fout << d[n-1][n-1] + 1;
}
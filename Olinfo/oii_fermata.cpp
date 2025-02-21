#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, s, c;
vector<vector<pair<int, int>>> prog;
vector<int> val;

vector<vector<int>> status, cycle;

bool f(int cell, int stato){
  if(cycle[cell][stato] != -1) return cycle[cell][stato];

  if(cell == 0){
    cycle[cell][stato] = 0;
    status[cell][stato] = 2;
  }

  if(status[cell][stato] == 1){
    status[cell][stato] = 2;
    cycle[cell][stato] = 1;
  }else if(status[cell][stato] == 0){
    status[cell][stato] = 1;
    cycle[cell][stato] = f(cell+prog[stato][val[cell]].second, prog[stato][val[cell]].first);
    status[cell][stato] = 2;
  }
  
  return cycle[cell][stato];
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  fin >> n >> s >> c;
  prog.resize(s, vector<pair<int, int>>(c));
  val.resize(n);
  status.resize(n, vector<int>(s));
  cycle.resize(n, vector<int>(s, -1));

  for(int i = 0; i < s*c; i++){
    int stato, caratt, next, dir;
    fin >> stato >> caratt >> next >> dir;
    prog[stato][caratt] = {next, dir};
  }

  for(auto &i : val) fin >> i;
  
  for(int i = 0; i < n; i++) for(int j = 0; j < s; j++) if(cycle[i][j] == -1) f(i, j);

  vector<int> cells;
  for(int i = 0; i < n; i++) if(!cycle[i][0]) cells.push_back(i);

  fout << cells.size() << '\n';
  for(auto i : cells) fout << i << '\n';
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int m, n, k; fin >> m >> n >> k;
  
  queue<char> q;
  for(int i = 0; i < k; i++){
    char c; fin >> c; q.push(c);
  }

  map<pair<char, int>, int> map;
  for(int i = 0; i < m; i++){
    int a, b; char c;
    fin >> a >> b >> c;
    map[{a, c}] = b;
  }
  
  int conf = 1;
  while(!q.empty()){
    conf = map[{conf, q.front()}];
    q.pop();
  }

  fout << conf;
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
int best = -1;
vector<int> v;

void f(int i){
  vector<bool> vis(n, 0);
  int curr = i;
  int tot = 0;

  while(1){
    if(vis[curr]){
      if(curr == i) best = max(best, tot);
      break;
    }else if(curr < i) break;

    tot++;
    vis[curr] = 1;
    curr = v[curr];  
  }

  return;
}

int main() {
  fin >> n;
  v.resize(n);

  for(int i = 0; i < n; i++) fin >> v[i];

  for(int i = 0; i < n; i++) f(i);
  
  fout << best;
}
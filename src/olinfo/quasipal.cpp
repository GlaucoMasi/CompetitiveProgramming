#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, curr = 0;
bool found = 0;
vector<string> v, ans;
vector<bool> used;
vector<vector<int>> sim;

void f(int i){
  if(found) return;

  if(curr == n/2){
    if(n%2){
      for(int k = 0; k < n; k++){
        if(!used[k]) ans[n/2] = v[k];
      }
    }

    for(int x = 0; x < n; x++){
      for(int y = 0; y < m; y++) fout << ans[x][y];
      fout << endl;
    }
  
    found = 1;
    return;
  }

  if(i > n-1) return;
  
  f(i+1);

  if(used[i]) return;

  used[i] = 1;
  ans[curr] = v[i];
  for(auto j : sim[i]){
    if(used[j]) continue;
    if(found) continue;

    ans[n-1-curr] = v[j];
    curr++;
    used[j] = 1;
    f(i+1);
    curr--;
    used[j] = 0;
  }
  used[i] = 0;

  return;
}

bool check(string a, string b){
  for(int i = 0; i < m; i++){
    if(a[i] != b[i] && a[i] != '0' && b[i] != '0') return false;
  }

  return true;
}

int main() {
  fin >> n >> m;
  v.resize(n);
  ans.resize(n);
  sim.resize(n);
  used.resize(n);

  for(int i = 0; i < n; i++){
    fin >> v[i];

    for(int j = 0; j < i; j++){
      if(check(v[i], v[j])){
        sim[i].push_back(j);
        sim[j].push_back(i);
      }
    }
  }

  f(0);
}
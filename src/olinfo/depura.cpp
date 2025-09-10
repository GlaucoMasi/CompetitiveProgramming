#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

// 0 = non aggiungibile
// 1 = giÃ  dentro
// 2 = con regola

int main() {
  int k, r;
  fin >> k >> r;

  vector<int> memo(2005, 0);
  vector<vector<int>> g(2005);

  int temp;
  for(int i = 0; i < k; i++){
    fin >> temp;
    memo[temp] = 1;
  }
  
  int n;
  for(int i = 0; i < r; i++){
    fin >> temp >> n;

    memo[temp] = 2;

    int temp1;
    for(int y = 0; y < n; y++){
      fin >> temp1;

      g[temp].push_back(temp1);
    }
  }

  int tot = 0;
  queue<int> q;
  q.push(1);

  bool fail = 0;

  while(!q.empty()){
    int curr = q.front();
    q.pop();

    if(memo[curr] == 0){
      fout << "-1";

      fail = 1;

      break;
    }else if(memo[curr] == 1) continue;
    else if(memo[curr] == 2){
      tot++;
      
      memo[curr] = 1;
      
      for(auto e : g[curr]) q.push(e);
    }
  }
  
  if(!fail) fout << tot;
}
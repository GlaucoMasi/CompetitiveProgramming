#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; cin >> n;
  vector<vector<int>> g(n);
  vector<int> need(n);
  queue<int> q;

  for(int i = 0; i < n; i++){
    int l; cin >> l;
    cin >> need[i];
    if(!need[i]) q.push(i);

    int a;
    for(int j = 0; j < l; j++){
      cin >> a;
      g[a].push_back(i);
    }
  }

  int tot = 0;
  while(!q.empty()){
    int curr = q.front(); q.pop();
    tot++;

    for(auto i : g[curr]){
      need[i]--;
      if(!need[i]) q.push(i);
    }
  }

  cout << tot;
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<vector<int>> g, c;

bool flow(vector<int> &fat){
  fill(fat.begin(), fat.end(), -1);
  queue<int> q; q.push(0); fat[0] = -2;

  while(!q.empty()){
    int i = q.front(); q.pop();

    if(i == 2*n+1) return 1;

    for(auto j : g[i]) if(fat[j] == -1 && c[i][j]){
      fat[j] = i;
      q.push(j);
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;

  g.resize(2*n+2);
  c.resize(2*n+2, vector<int>(2*n+2));

  int tota = 0, totb = 0;
  vector<int> a(n), b(n);
  for(auto &i : a) cin >> i, tota += i;
  for(auto &i : b) cin >> i, totb += i;

  if(tota != totb){
    cout << -1;
    return 0;
  }

  for(int i = 1; i <= n; i++){
    g[0].push_back(i);
    g[i].push_back(0);
    c[0][i] = a[i-1];

    g[n+i].push_back(2*n+1);
    g[2*n+1].push_back(n+i);
    c[n+i][2*n+1] = b[i-1];
  
    for(int j = 1; j <= n; j++){
      g[i].push_back(n+j);
      g[n+j].push_back(i);
      c[i][n+j] = 1;
    }
  }

  int tot = 0, temp;
  vector<int> fat(2*n+2);
  while(temp = flow(fat)){
    tot++;

    int i = 2*n+1;
    while(i != 0){
      c[fat[i]][i]--;
      c[i][fat[i]]++;
      i = fat[i];
    }
  }

  if(tot != tota){
    cout << -1;
    return 0;
  }

  for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++){
    if(c[i][n+j]) cout << '.';
    else cout << 'X';
    if(j == n) cout << '\n';
  }
}
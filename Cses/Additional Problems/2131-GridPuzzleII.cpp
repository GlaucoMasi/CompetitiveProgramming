#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<vector<pair<int, int>>> g;
vector<vector<int>> c;

long long flow(vector<int> &fat){
  queue<int> q;
  vector<bool> in(2*n+2);
  vector<long long> dist(2*n+2, -2e18);
  dist[0] = 0; q.push(0); in[0] = 1;

  while(!q.empty()){
    int i = q.front(); q.pop();
    in[i] = 0;

    for(auto [j, add] : g[i]) if(c[i][j] && dist[j] < dist[i]+add){
      fat[j] = i;
      dist[j] = dist[i]+add;
      if(!in[j]){
        in[j] = 1;
        q.push(j);
      }
    }
  }

  return dist[2*n+1];
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

  for(int i = 1; i <= n; i++){
    g[0].push_back({i, 0});
    g[i].push_back({0, 0});
    c[0][i] = a[i-1];

    g[n+i].push_back({2*n+1, 0});
    g[2*n+1].push_back({n+i, 0});
    c[n+i][2*n+1] = b[i-1];

    for(int j = 1; j <= n; j++){
      int temp; cin >> temp;
      g[i].push_back({n+j, temp});
      g[n+j].push_back({i, -temp});
      c[i][n+j] = 1;
    }
  }

  if(tota != totb){
    cout << -1;
    return 0;
  }

  int tot = 0;
  long long ans = 0, k;
  vector<int> fat(2*n+2);
  while((k = flow(fat)) != -2e18){
    ans += k; tot++;

    int i = 2*n+1;
    while(i != 0){
      c[fat[i]][i]--;
      c[i][fat[i]]++;
      i = fat[i];
    }
  }

  if(tot != tota) cout << -1;
  else{
    cout << ans << '\n';
    for(int i = 1; i <= n; i++){
      for(int j = 1; j <= n; j++){
        if(c[i][n+j]) cout << '.';
        else cout << 'X';
      }

      cout << '\n';
    }
  }
}
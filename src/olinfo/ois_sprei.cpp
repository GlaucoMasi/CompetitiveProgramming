#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, b;
map<vector<int>, int> hashing;
vector<vector<pair<int, int>>> g;
vector<int> st, en;
vector<vector<int>> c;

int flow(vector<pair<int, int>> &fat){
  queue<int> q;
  fill(fat.begin(), fat.end(), make_pair(-1, -1));

  q.push(0); fat[0] = {-2, -2};
  while(!q.empty()){
    int i = q.front(); q.pop();

    if(i == n+1) return 1;

    for(auto [j, t] : g[i]) if(fat[j].first == -1){
      if(i == 0 && !st[j]) continue;
      if(i == n+1 && !en[j]) continue;
      if(i != 0 && i != n+1 && !c[i][t]) continue;
      fat[j] = {i, t};
      q.push(j);
    }
  }

  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m >> b;
  g.resize(n+2);
  c.resize(n+1, vector<int>(2*m+1));
  st.resize(n+1); en.resize(n+1);

  for(int i = 1; i <= n; i++){
    int tot = 0;
    vector<int> v(m);
    for(auto &i : v) cin >> i, tot += i;
    hashing[v] = i;

    if(tot%2){
      g[i].push_back({n+1, 2*m});
      g[n+1].push_back({i, -1});
      c[i][2*m] = 1;
    }else{
      g[0].push_back({i, -1});
      g[i].push_back({0, 2*m});
      st[i] = 1;
    }
  }

  for(auto [vect, idx] : hashing){
    int tot = 0;
    auto temp = vect;
    for(auto i : temp) tot += i;

    for(int i = 0; i < m; i++){
      temp[i]++;
      if(hashing.count(temp)){
        g[idx].push_back({hashing[temp], m+i});
        g[hashing[temp]].push_back({idx, i});
        if(tot%2) c[hashing[temp]][i] = 1;
        else c[idx][m+i] = 1;
      }
      temp[i]--;
    }
  }

  int tot = 0;
  vector<pair<int, int>> fat(n+2);
  while(flow(fat)){
    int i = fat[n+1].first; tot++;

    c[i][2*m]--;
    en[i]++;

    while(fat[i].first != 0){
      int a = fat[i].second, b = (a >= m ? a-m : a+m);
      c[fat[i].first][a]--;
      c[i][b]++;
      i = fat[i].first;
    }

    c[i][2*m]++;
    st[i]--;
  }

  cout << tot;
}
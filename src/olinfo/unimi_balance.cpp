#include <bits/stdc++.h>
using namespace std;

int n; long long tot = 0;
vector<vector<pair<int, long long>>> g;

long long f(int i){
  if(!g[i].size()) return 0;
  
  long long high = 0, sum = 0;

  for(auto j : g[i]){
    long long temp = j.second+f(j.first);
    high = max(high, temp);
    sum += temp;
  }

  tot += high*g[i].size()-sum;
  return high*g[i].size();
}

int main() {
  cin >> n;
  g.resize(n);

  for(int i = 1; i < n; i++){
    int a, b; cin >> a >> b;
    g[a].push_back({i, b});
  }

  f(0);
  cout << tot;
}
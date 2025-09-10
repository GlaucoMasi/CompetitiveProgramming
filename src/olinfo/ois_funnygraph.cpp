#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<array<int, 3>>> g;

vector<long long> val; 
vector<bool> done;

bool f(int i, int l){
  for(auto [j, c, k] : g[i]){
    if(k > l) continue;

    if(done[j]){
      if(val[i] - c != val[j]) return 0;
    }else{
      val[j] = val[i] - c;
      done[j] = 1;
      if(!f(j, l)) return 0;
    }
  }

  return 1;
}

bool test(int l){
  val.clear();
  val.resize(n);

  done.clear();
  done.resize(n);

  for(int i = 0; i < n; i++){
    if(done[i]) continue;

    done[i] = 1;
    if(!f(i, l)) return 0;
  }

  return 1;
}

int main() {
  cin >> n >> m;
  g.resize(n);

  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;

    g[a].push_back({b, c, i});
    g[b].push_back({a, -c, i});
  }

  int l = 0, r = m;
  while(l < r-1){
    int m = (l+r)/2;

    if(test(m)) l = m;
    else r = m;
  }

  cout << l+1;
}
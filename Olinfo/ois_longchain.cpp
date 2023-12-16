#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<int>> g;

int f(int i, int p){
  if(g[i].size() == 1) return 0;

  vector<int> v;
  for(auto j : g[i]) if(j != p) v.push_back(f(j, i)+1);
  sort(v.begin(), v.end());

  if(v[0] < 0) return -1e9;

  auto test = [&](){
    if(v.size() == 1) return v[0];

    bool ok = 1;
    for(int i = 1; i <= v.size()/2; i++) if(v[i] + v[v.size()-i] < k) ok = 0;
    if(!ok) return (int)(-1e9);

    int l = 0, r = v.size();
    while(l < r-1){
      int m = (l+r)/2;

      bool fail = 0;
      int i = 0, j = v.size()-1;
      while(1){
        if(i == m) i++; if(j == m) j--;
        if(i >= j) break;

        if(v[i]+v[j] < k) fail = 1;

        i++; j--;
      }

      if(!fail) l = m;
      else r = m;
    }

    return v[l];
  };

  if(v.size()%2) return test();
  else{
    if(v.back() >= k){
      v.pop_back();
      return test();
    }else{
      for(int i = 0; i < v.size()/2; i++) if(v[i]+v[v.size()-1-i] < k) return -1e9;
      return 0;
    }
  }
}

int main() {
  cin >> n; g.resize(n);

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[a-1].push_back(b-1);
    g[b-1].push_back(a-1);
  }

  int l = 0, r = n;
  while(l < r-1){
    k = (l+r)/2;

    vector<int> v;
    for(auto j : g[0]) v.push_back(f(j, 0)+1);
    sort(v.begin(), v.end());

    bool success = 1;
    if(v[0] > 0){
      if(g[0].size()%2){
        if(v.back() < k) success = 0;
        v.pop_back(); 
      }

      for(int i = 0; i < v.size()/2; i++) if(v[i] + v[v.size()-1-i] < k) success = 0;
    }else success = 0;

    if(success) l = k;
    else r = k;
  }

  cout << l;
}
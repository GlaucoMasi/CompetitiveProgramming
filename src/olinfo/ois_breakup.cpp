#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<vector<pair<int, int>>> inv;
vector<int> tot, fav;
set<int> s;
vector<char> ans;

void proc(int i){
  s.erase(i);
  ans[i] = 'G';
}

void f(int i){
  vector<int> next;

  for(auto j : inv[i]){
    if(!s.count(j.first)) continue;

    fav[j.first] -= j.second;
    if(fav[j.first] < tot[j.first]-fav[j.first]){
      proc(j.first);
      next.push_back(j.first);
    }
  }

  for(auto i : next) f(i);
}

int main() {
  cin >> n >> m;
  inv.resize(n);
  tot.resize(n, 0); fav.resize(n, 0);
  ans.resize(n, 'W'); ans[n-1] = 'G';

  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;

    inv[b].push_back({a, c});
    tot[a] += c; if(b != n-1) fav[a] += c;
  }

  for(int i = 1; i < n-1; i++) s.insert(i);

  while(1){
    int start = -1;

    for(auto i : s){
      if(fav[i] < tot[i]-fav[i]){
        start = i;
        break;
      }
    }

    if(start == -1) break;
    else{
      proc(start);
      f(start);
    }
  }

  for(auto i : ans) cout << i;
}
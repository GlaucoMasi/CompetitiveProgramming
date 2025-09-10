#include <bits/stdc++.h>
using namespace std;

int n; vector<bool> ans;
vector<pair<pair<long long, long long>, int>> v;

void f(){
  vector<pair<pair<long long, long long>, int>> curr; 
  curr.push_back(v[0]); curr.push_back(v[1]);

  for(int i = 2; i <= n; i++){
    while(curr.size() >= 2){
      pair<long long, long long> v1 = {curr[curr.size()-1].first.first-curr[curr.size()-2].first.first, curr[curr.size()-1].first.second-curr[curr.size()-2].first.second};
      pair<long long, long long> v2 = {v[i].first.first-curr[curr.size()-2].first.first, v[i].first.second-curr[curr.size()-2].first.second};
    
      if(v1.second*v2.first-v1.first*v2.second <= 0) curr.pop_back();
      else break;
    }

    curr.push_back(v[i]);
  }

  for(auto i : curr){
    if(i.second != -1) ans[i.second] = 1;
  }
}

vector<int> trovacerchi(int N, vector<int> X, vector<int> Y){
  n = N;
  v.resize(n); ans.resize(n);
  for(int i = 0; i < n; i++) v[i] = {{X[i], Y[i]}, i};
  v.push_back({{0, 0}, -1});

  sort(v.begin(), v.end());
  f();
  reverse(v.begin(), v.end());
  f();

  vector<int> t;
  for(int i = 0; i < n; i++) if(ans[i]) t.push_back(i);
  return t;
}
#include <bits/stdc++.h>
using namespace std;

vector<pair<int, long long>> su, giu;
vector<vector<pair<int, long long>>> g;
vector<bool> fil;
pair<long long, int> best = {1e18, 0};

void f1(int i, int fat, long long l){
  for(auto j : g[i]){
    if(j.first == fat) continue;

    f1(j.first, i, j.second);
    giu[i].first += giu[j.first].first + fil[j.first];
    giu[i].second += giu[j.first].second + j.second*giu[j.first].first + j.second*fil[j.first];
  }
}

void f2(int i, int fat, long long l){
  if(fat != -1){
    su[i].first += su[fat].first + fil[fat];
    su[i].second += su[fat].second + l*su[fat].first + l*fil[fat];
  }

  for(auto j : g[i]){
    if(j.first == fat) continue;

    su[j.first].first += giu[i].first-giu[j.first].first - fil[j.first];
    su[j.first].second += giu[i].second-giu[j.first].second - j.second*giu[j.first].first - j.second*fil[j.first];
    su[j.first].second += j.second*(giu[i].first-giu[j.first].first - fil[j.first]);
    f2(j.first, i, j.second);
  }

  best = min(best, {su[i].second+giu[i].second, i});
}

int trova_sede(int n, int k, int a[], int b[], int p[], int filiali[]){
  su.resize(n); giu.resize(n); g.resize(n); fil.resize(n);

  for(int i = 0; i < n-1; i++){
    g[a[i]-1].push_back({b[i]-1, p[i]});
    g[b[i]-1].push_back({a[i]-1, p[i]});
  }

  for(int i = 0; i < k; i++) fil[filiali[i]-1] = 1;

  f1(0, -1, 0); f2(0, -1, 0);

  return best.second+1;
}
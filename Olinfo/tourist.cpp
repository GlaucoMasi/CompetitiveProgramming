#include <bits/stdc++.h>
using namespace std;

int n, k;
int best = 0, curr = 0;
vector<bool> taken;
vector<pair<int, int>> sorted;

int r, j = 0;

void add(){
  while(j < n && (taken[sorted[j].second] || sorted[j].second > r)) j++;
  if(j == n) return;

  taken[sorted[j].second] = 1;
  curr -= sorted[j].first;
  j++;

  best = max(best, curr);
}

int GreatestHappiness(int n, int k, int *v) {
  ::n = n, ::k = k;

  taken.resize(n);
  for(int i = 0; i < n; i++) sorted.push_back({-v[i], i});
  sort(sorted.begin(), sorted.end());

  r = min(n-1, k);
  for(int i = 0; i < k-n+1; i++) add();

  while(r != 0){
    r--; 

    if(taken[r+1]){
      curr -= v[r+1];
      add();
    }

    add();
  }

  return best;
}
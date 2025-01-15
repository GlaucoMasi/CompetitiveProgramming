#include <bits/stdc++.h>
using namespace std;

int comps;
vector<int> sz, fat;

int get(int i){
  if(i == fat[i]) return i;
  return fat[i] = get(fat[i]);
}

void join(int a, int b){
  a = get(a); b = get(b);

  if(a == b) return;
  if(sz[a] < sz[b]) swap(a, b);

  comps--;
  sz[a] += sz[b];
  fat[b] = a;
}

void inizia(int n) {
  fat.resize(n);
  sz.resize(n, 1);
  iota(fat.begin(), fat.end(), 0);
  comps = n;
}

int collega(int a, int b) {
  join(a, b);
  return comps;
}
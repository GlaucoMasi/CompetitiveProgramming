#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct fenwick{
  vector<int> v;

  fenwick(int n){
    v.resize(n+1, 0);
  }

  void add(int i, int k){
    for(int p = i; p < v.size(); p += (p & -p)){
      v[p] += k;
    }
  }

  int sum(int i){
    if(i >= v.size()) return 1e9;

    int ans = 0;

    for(int p = i; p > 0; p -= (p & -p)){
      ans += v[p];
    }

    return ans;
  }

  int find(int i){
    int l = 1, r = v.size()-1;
  
    while(l < r){
      int m = l + (r-l)/2;

      if(sum(m) >= i) r = m;
      else l = m+1;
    }

    return l;
  }
};

vector<vector<int>> g;
fenwick fw(1e6+5);

int f(int i, int fat, int d, vector<int> &dolcezza, vector<int> &C){
  fw.add(dolcezza[i], 1);
  
  if(g[i].size() == 1 && i != 0 && dolcezza.size() !=  1){
    int temp = fw.find(C[i]+1);
    fw.add(dolcezza[i], -1);

    return temp;
  }

  int minimo = 2e9, massimo = -2e9;
  for(auto j : g[i]){
    if(j != fat){
      int temp = f(j, i, d+1, dolcezza, C);
      minimo = min(minimo, temp);
      massimo = max(massimo, temp);
    }
  }

  fw.add(dolcezza[i], -1);
  
  if(d%2) return minimo;
  else return massimo;
}

int visita(int N, vector<int> &A, vector<int> &B, vector<int> &dolcezza,
vector<int> &C){
  g.resize(N);

  for(int i = 0; i < N-1; i++){
    g[A[i]].push_back(B[i]);
    g[B[i]].push_back(A[i]);
  }

  vector<pair<int, int>> sorting(N);
  for(int i = 0; i < N; i++) sorting[i] = {dolcezza[i], i};
  sort(sorting.begin(), sorting.end());
  for(int i = 0; i < N; i++) dolcezza[sorting[i].second] = i+1;

  return sorting[f(0, -1, 0, dolcezza, C)-1].first;
}
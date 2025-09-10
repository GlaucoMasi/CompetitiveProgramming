#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g;
array<long long, 3> tot;
vector<array<long long, 3>> freq;
vector<array<bool, 3>> spec;
vector<long long> ans;

void calc(int i, int p){
  for(int k = 0; k < 3; k++) freq[i][k] += spec[i][k];
  for(auto j : g[i]) if(j != p){
    calc(j, i);
    for(int k = 0; k < 3; k++) freq[i][k] += freq[j][k];
  }
}

array<long long, 3> get(int i, int j, int p){
  if(j != p) return freq[j];
  array<long long, 3> freqs;
  for(int k = 0; k < 3; k++) freqs[k] = tot[k]-freq[i][k];
  return freqs;
}

void f(int i, int p){
  if(spec[i][0] && spec[i][1] && spec[i][2]) ans[i]++;
  
  for(int ex = 0; ex < 3; ex++){
    bool ok = 1;
    for(int k = 0; k < 3; k++) if(k != ex && !spec[i][k]) ok = 0;
    if(ok) ans[i] += tot[ex]-spec[i][ex];
  }

  long long totnum = 0;
  for(auto j : g[i]){
    array<long long, 3> freqs = get(i, j, p);
    totnum += freqs[1]*(tot[2]-freqs[2]-spec[i][2]);
  }
  
  for(auto j : g[i]){
    array<long long, 3> freqs = get(i, j, p);
    
    for(int here = 0; here < 3; here++){
      if(!spec[i][here]) continue;
      int idx1 = (here ? 0 : 1), idx2 = (here == 2 ? 1 : 2);
      ans[i] += freqs[idx1]*(tot[idx2]-freqs[idx2]-spec[i][idx2]);
    }

    ans[i] += freqs[0]*(totnum - freqs[1]*(tot[2]-freqs[2]-spec[i][2]) - (tot[1]-freqs[1]-spec[i][1])*freqs[2]);
  }

  for(auto j : g[i]) if(j != p) f(j, i);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  g.resize(n);
  freq.resize(n);
  spec.resize(n);
  ans.resize(n);

  for(int i = 0; i < n-1; i++){
    int a, b, c;
    cin >> a >> b >> c;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  for(int k = 0; k < 3; k++){
    cin >> tot[k];
    for(int i = 0; i < tot[k]; i++){
      int a; cin >> a;
      spec[a][k] = 1;
    }
  }

  calc(0, -1);
  f(0, -1);
  for(auto i : ans) cout << i << " ";
}
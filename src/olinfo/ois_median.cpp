#include <bits/stdc++.h>
using namespace std;
ofstream fout("output.txt");

int n; long long k, tot;
vector<pair<int, int>> g[50000];
vector<int> centrs;
int sz[50000], t[50000], subsz[50000];

void calc(int i, int f){
  sz[i] = 1;
  for(auto [j, c] : g[i]) if(j != f && !t[j]){
    calc(j, i);
    sz[i] += sz[j];
  }
}

void prec(int i){
  calc(i, -1);

  bool found = 0;
  int centr = i, f = -1;
  while(!found){
    found = 1;
    for(auto [j, c] : g[centr]) if(j != f && !t[j] && sz[j] > sz[i]/2){
      f = centr;
      centr = j;
      found = 0;
      break;
    }
  }

  centrs.push_back(centr); t[centr] = centrs.size(); subsz[centr] = sz[i];
  for(auto [j, c] : g[centr]) if(!t[j]) prec(j);
}

int off, start, m;
vector<int> buffer;
void sub(int i, int f, int l, vector<long long> &d){
  tot += d[off-l];
  buffer.push_back(l);
  for(auto [j, c] : g[i]) if(j != f && t[j] > start) sub(j, i, l + (c > m ? 1 : -1), d);
}

bool test(int curr){
  tot = 0; m = curr;

  for(auto i : centrs){
    off = subsz[i]-1; start = t[i];
    vector<long long> d(2*subsz[i]-1), add(2*subsz[i]-1);
    for(int j = off; j < d.size(); j++) d[j] = 1;

    for(auto [j, c] : g[i]){
      if(t[j] < start) continue;
      sub(j, -1, (c > m ? 1 : -1), d);

      int l = 1e9;
      for(auto x : buffer) add[off+x]++, l = min(l, off+x);
      buffer.clear();

      long long t = 0;
      for(int x = l; x < d.size(); x++){
        t += add[x];
        d[x] += t;
        add[x] = 0;
      }
    }
  }

  return (tot >= k);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  cin >> n >> k;

  for(int i = 0; i < n-1; i++){
    int a, b, c; cin >> a >> b >> c;
    g[--a].push_back({--b, c});
    g[b].push_back({a, c});
  }

  prec(0);

  int l = 0, r = 1e9+1;
  while(l < r-1){
    int m = l + (r-l)/2;

    if(test(m)) r = m;
    else l = m;
  }

  cout << l+1;
}
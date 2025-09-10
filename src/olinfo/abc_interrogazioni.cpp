#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

long long ans = 0;

struct st{
  int size = 1;
  vector<int> v;

  st(int n){
    while(size < n) size *= 2;
    v.resize(2*size);
  }

  void add(int i){
    int u = size+i;
    v[u] = 1;

    while(u > 1){
      u /= 2;
      v[u] = v[2*u]+v[2*u+1];
    }
  }

  int get(int u, int l, int r, int x){
    if(r <= x) return 0;
    if(l >= x) return v[u];

    return get(2*u, l, l + (r-l)/2, x) + get(2*u+1, l + (r-l)/2, r, x);
  }

  void process(int i){
    ans += get(1, 0, size, i+1);
    add(i);
  }
};

bool comp(pair<int, int> a, pair<int, int> b){ return a.second < b.second; }

int main() {
  int n; fin >> n;
  vector<pair<int, int>> v(n);
  for(int i = 0; i < n; i++){ fin >> v[i].first; v[i].second = i; }
  st st(n);

  sort(v.begin(), v.end());
  for(int i = 0; i < n; i++) v[i].first = i;
  sort(v.begin(), v.end(), comp);

  for(auto i : v) st.process(i.first);

  fout << ans;
}
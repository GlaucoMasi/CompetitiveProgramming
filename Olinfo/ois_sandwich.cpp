#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct st{
  int sz = 1;
  vector<int> v;

  st(int n){
    while(sz < n) sz *= 2;
    v.resize(2*sz, -1e9);
  }

  void upd(int u, int k){
    u += sz;
    v[u] = max(v[u], k);
    while(u > 1){
      u /= 2;
      v[u] = max(v[2*u], v[2*u+1]);
    }
  }

  int get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return -1e9;
    if(l >= x && r <= y) return v[u];
    return max(
      get(2*u, l, (l+r)/2, x, y),
      get(2*u+1, (l+r)/2, r, x, y)
    );
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> v(n); for(auto &i : v) cin >> i;

  vector<long long> comp(v.begin(), v.end());
  for(int i = 1; i < n; i++) comp[i] += comp[i-1]; comp.push_back(0);
  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end())-comp.begin());
  unordered_map<long long, int> m;
  for(int i = 0; i < comp.size(); i++) m[comp[i]] = i;

  long long curr = 0;
  st st(comp.size()); st.upd(m[0], 0);
  for(int i = 0; i < n; i++){
    curr += v[i];
    int best = st.get(1, 0, st.sz, 0, m[curr])+1;
    st.upd(m[curr], best);
  }

  cout << st.v[st.sz+m[curr]];
}
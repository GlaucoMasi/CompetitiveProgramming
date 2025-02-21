#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct st{
  struct node{
    long long big = -1e18, small = -1e18;
    void join(const node &l, const node &r){
      small = max(l.small, r.small);
      big = max(l.big, r.big);
    }
  };

  int sz = 1;
  vector<node> v;

  st(int n){
    while(sz < n) sz *= 2;
    v.resize(2*sz);
  }

  void upd(int i, long long a, long long b){
    i += sz;
    v[i].small = max(v[i].small, a);
    v[i].big = max(v[i].big, b);

    while(i > 1){
      i /= 2;
      v[i].join(v[2*i], v[2*i+1]);
    }
  }

  long long get(int u, int l, int r, int x, int y, bool type){
    if(l >= y || r <= x) return -1e18;
    if(l >= x && r <= y) return (type ? v[u].big : v[u].small);
    return max(
      get(2*u, l, (l+r)/2, x, y, type),
      get(2*u+1, (l+r)/2, r, x, y, type)
    );
  }
};

void solve() {
  int n; cin >> n;
  vector<int> v(n); for(auto &i : v) cin >> i;

  vector<int> comp = v;
  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end())-comp.begin());
  unordered_map<int, int> m;
  for(int i = 0; i < comp.size(); i++) m[comp[i]] = i;
  for(auto &i : v) i = m[i];

  st st(comp.size());
  long long last = 0;
  for(int i = 0; i < n; i++){
    st.upd(v[i], last-comp[v[i]], last+comp[v[i]]);
    long long big = comp[v[i]]+st.get(1, 0, st.sz, 0, v[i]+1, 0);
    long long small = -comp[v[i]]+st.get(1, 0, st.sz, v[i], st.sz, 1);
    last = max({last, small, big});
  }

  cout << last << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while(t--) solve();
}
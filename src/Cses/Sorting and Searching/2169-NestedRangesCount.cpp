#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct st{
  int sz = 1;
  vector<int> v;

  st(int n){
    while(sz < n) sz *= 2;
    v.resize(2*sz);
  }

  void add(int u){
    v[u+=sz]++;
    while(u > 1){
      u /= 2;
      v[u]++;
    }
  }

  int get(int l){
    int ans = 0, r = sz;

    for (l += sz, r += sz; l < r; l >>= 1, r >>= 1) {
      if(l&1) ans += v[l++];
      if(r&1) ans += v[--r];
    }

    return ans;
  }
};

bool comp1(const array<int, 3> &l, const array<int, 3> &r){
  return (make_pair(l[1], -l[0]) < make_pair(r[1], -r[0]));
}

bool comp2(const array<int, 3> &l, const array<int, 3> &r){
  return (make_pair(l[0], -l[1]) < make_pair(r[0], -r[1]));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<array<int, 3>> v(n);
  vector<bool> in(n), out(n);
  for(int i = 0; i < n; i++) cin >> v[i][0] >> v[i][1], v[i][2] = i;
  
  vector<int> comp;
  unordered_map<int, int> m;
  for(auto &[l, r, i] : v) comp.push_back(l), comp.push_back(r);
  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end())-comp.begin());
  for(int i = 0; i < comp.size(); i++) m[comp[i]] = i;
  for(auto &[l, r, i] : v) l = m[l], r = m[r];

  st st(comp.size());
  vector<int> ans1(n), ans2(n);
  sort(v.begin(), v.end(), comp1);

  for(auto [l, r, idx] : v){
    ans1[idx] = st.get(l);
    st.add(l);
  }

  cout << '\n';
  fill(st.v.begin(), st.v.end(), 0);
  sort(v.begin(), v.end(), comp2);

  for(auto [l, r, idx] : v){
    ans2[idx] = st.get(r);
    st.add(r);
  }

  for(auto i : ans1) cout << i << " "; cout << '\n';
  for(auto i : ans2) cout << i << " ";
}
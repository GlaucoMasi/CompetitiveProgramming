#include <bits/stdc++.h>
using namespace std;

struct ST{
  int sz;
  vector<int> v;

  void upd(int val){
    int u = sz+val;
    v[u]++;

    while(u > 1){
      u /= 2;
      v[u]++;
    }
  }

  int get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u];

    return get(2*u, l, l + (r-l)/2, x, y) + get(2*u+1, l + (r-l)/2, r, x, y);
  }
};

ST st;

void solve() {
  int s, t; cin >> s >> t;
  vector<int> a(s), b(t);
  for(auto &i : a) cin >> i;
  for(auto &i : b) cin >> i;
  sort(b.begin(), b.end());

  vector<int> ans(t);

  queue<array<int, 4>> v; v.push({0, s-1, 0, t-1});
  while(!v.empty()){
    auto [l1, r1, l2, r2] = v.front(); v.pop();
    if(l2 > r2) continue;

    int m = l2 + (r2-l2)/2;
    pair<int, int> best = {0, l1};
    for(int i = l1; i <= r1; i++) if(a[i] < b[m]) best.first++;

    int curr = best.first;
    for(int i = l1; i <= r1 && i < s; i++){
      if(a[i] < b[m]) curr--;
      else if(a[i] > b[m]) curr++;
      best = min(best, {curr, i+1});
    }

    ans[m] = best.second;
    v.push({l1, best.second, l2, m-1});
    v.push({best.second, r1, m+1, r2});
  }

  vector<int> done;
  int i = 0, j = 0;
  while(i < s && j < t){
    if(ans[j] <= i){
      done.push_back(b[j]);
      j++;
    }else{
      done.push_back(a[i]);
      i++;
    }
  }

  for(i; i < s; i++) done.push_back(a[i]);
  for(j; j < t; j++) done.push_back(b[j]);

  vector<int> all;
  sort(a.begin(), a.end());
  
  i = 0, j = 0;
  while(i < s || j < t){
    if(i < s && (j >= t || a[i] < b[j])){
      if(all.empty() || a[i] != all.back()) all.push_back(a[i]);
      i++;
    }else{
      if(all.empty() || b[j] != all.back()) all.push_back(b[j]);
      j++;
    }
  }

  for(auto &i : done) i = lower_bound(all.begin(), all.end(), i)-all.begin();

  int sz = 1;
  while(sz < all.size()) sz *= 2; st.sz = sz;
  for(int i = 0; i < 2*sz; i++) st.v[i] = 0;

  long long tot = 0;
  for(auto i : done){
    tot += st.get(1, 0, sz, i+1, sz);
    st.upd(i);
  }

  cout << tot << '\n';
}

int main() {
  ios_base::sync_with_stdio(0);cin.tie(0);

  int t; cin >> t;
  st.v.resize(4194304);
  while(t--) solve();
}
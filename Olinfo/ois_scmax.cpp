#include <bits/stdc++.h>
using namespace std;

struct st{
  int size = 1;
  vector<int> v;

  st(int n){
    while(size < n) size *= 2;
    v.resize(2*size);
  }

  void upd(int u, int k){
    u += size;

    if(v[u] >= k) return;
    v[u] = k;

    while(u > 1){
      u /= 2;
      v[u] = max(v[2*u], v[2*u+1]);
    }
  }

  int query(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u];

    return max(
      query(2*u, l, l + (r-l)/2, x, y),
      query(2*u+1, l + (r-l)/2, r, x, y)
    );
  }
};

int main() {
  int n; cin >> n;
  vector<int> v(n), c(n);
  for(auto &i : v) cin >> i;
  for(auto &i : c) cin >> i;

  st st(n);
  vector<int> best(n);
  int ans = 0;

  for(int i = 0; i < n; i++){
    int note = v[i]-1;

    int temp = st.query(1, 0, st.size, 0, note);
    temp = max(temp, best[note]);
    temp++;

    st.upd(note, temp);
    best[c[note]-1] = max(best[c[note]-1], temp);
    ans = max(ans, temp);
  }

  cout << ans;
}
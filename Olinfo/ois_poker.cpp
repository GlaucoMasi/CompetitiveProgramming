#include <bits/stdc++.h>
using namespace std;

int n;
long long ans;
vector<vector<int>> v;

int sz = 1024;

struct st{
  vector<long long> v;

  long long get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u];

    return max(
      get(2*u, l, l + (r-l)/2, x, y),
      get(2*u+1, l + (r-l)/2, r, x, y)
    );
  }

  void upd(int u, long long k){
    ans = max(ans, k);
    u += sz; v[u] = max(v[u], k);

    while(u > 1){
      u /= 2;
      v[u] = max(v[2*u], v[2*u+1]);
    }
  }
};

int main() {
  cin >> n >> ans;

  v.resize(n+1, vector<int>(5, -1));
  for(int i = 1; i <= n; i++) for(int j = 0; j < 5; j++) cin >> v[i][j];

  sort(v.begin(), v.end());

  st st;

  for(int i = 1; i <= n; i++){
    if(v[i][0] != v[i-1][0]){
      st.v.clear();
      st.v.resize(2*sz, 0);
      st.upd(0, ans);
    }

    long long temp = st.get(1, 0, sz, 0, v[i][1]+1);
    if(temp >= v[i][3]) temp += (long long)max(0, v[i][4]-v[i][3]);
    st.upd(v[i][2], temp);
  }

  cout << ans;
}
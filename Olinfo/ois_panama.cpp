#include <bits/stdc++.h>
using namespace std;

static long long INF = -1e18;

struct st{

  struct node{
    long long best, pref, suff, sum;
    
    node(long long k){ best = pref = suff = sum = k; }
    void update(long long k){ best = pref = suff = sum = k; }

    void join(const node &l, const node &r){
      sum = l.sum + r.sum;
      pref = max(l.pref, l.sum + r.pref);
      suff = max(r.suff, r.sum + l.suff);

      best = max(l.best, r.best);
      best = max(best, l.suff + r.pref);
    }
  };

  int size = 1;
  vector<node> v;

  st(vector<int> &data){
    while(size < data.size()) size *= 2;
    v.resize(2*size, node(INF));

    build(1, 0, size, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1){
      if(l < data.size()) v[u] = node(data[l]);
      return;
    }

    build(2*u, l, l + (r-l)/2, data);
    build(2*u+1, l + (r-l)/2, r, data);
    v[u].join(v[2*u], v[2*u+1]);
  }

  void upd(int i, int k){
    int u = size + i;
    v[u].update(k);

    while(u > 1){
      u /= 2;
      v[u].join(v[2*u], v[2*u+1]);
    }
  }

  long long get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return INF;
    if(l >= x && r <= y) return v[u].best;

    long long ans = max(get(2*u, l, l + (r-l)/2, x, y), get(2*u+1, l + (r-l)/2, r, x, y));
    ans = max(ans, suffix(2*u, l, l + (r-l)/2, x, y) + prefix(2*u+1, l + (r-l)/2, r, x, y));
    return ans;
  }

  long long prefix(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return INF;
    if(l >= x && r <= y) return v[u].pref;

    return max(sum(2*u, l, l + (r-l)/2, x, y) + prefix(2*u+1, l + (r-l)/2, r, x, y), prefix(2*u, l, l + (r-l)/2, x, y));
  }

  long long suffix(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return INF;
    if(l >= x && r <= y) return v[u].suff;

    return max(sum(2*u+1, l + (r-l)/2, r, x, y) + suffix(2*u, l, l + (r-l)/2, x, y), suffix(2*u+1, l + (r-l)/2, r, x, y));
  }

  long long sum(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u].sum;

    return sum(2*u, l, l + (r-l)/2, x, y) + sum(2*u+1, l + (r-l)/2, r, x, y);
  }
};

int main() {
  int n, q; cin >> n >> q;
  vector<int> v1(n); for(auto &i : v1) cin >> i;

  for(int i = 0; i < n; i++) if(i%2) v1[i] *= -1;

  vector<int> v2 = v1;
  for(auto &i : v2) i *= -1;

  st st1(v1);
  st st2(v2);
  
  int a, b, c;
  while(q--){
    cin >> a >> b >> c;
    
    if(a == 2){
      cout << max(st1.get(1, 0, st1.size, b-1, c), st2.get(1, 0, st2.size, b-1, c)) << endl;
    }else{
      st1.upd(b-1, (((b-1)%2) ? -c : c));
      st2.upd(b-1, (((b-1)%2) ? c : -c));
    }
  }
}
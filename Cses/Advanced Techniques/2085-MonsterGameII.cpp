#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct line{
  long long m, q;
  long long eval(long long x){ return m*x+q; }
};

const int sz = 1048576;
line v[2*sz];

void add(line n, int u = 1, int l = 0, int r = sz){
  int m = (l+r)/2;

  bool left = v[u].eval(l) > n.eval(l);
  bool mid = v[u].eval(m) > n.eval(m);

  if(mid) swap(n, v[u]);

  if(l == r-1) return;
  else if(left != mid) add(n, 2*u, l, m);
  else add(n, 2*u+1, m, r);
}

long long get(int x, int u = 1, int l = 0, int r = sz){
  int m = (l+r)/2;
  long long curr = v[u].eval(x);

  if(l == r-1) return curr;
  else if(x < m) return min(curr, get(x, 2*u, l, m));
  else return min(curr, get(x, 2*u+1, m, r));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, x; cin >> n >> x;
  vector<long long> s(n), f(n);
  for(auto &i : s) cin >> i;
  for(auto &i : f) cin >> i;

  for(auto &i : v) i.m = x, i.q = 0;

  for(int i = 0; i < n; i++){
    long long best = get(s[i]);
    if(i == n-1) cout << best;
    add({f[i], best});
  }
}
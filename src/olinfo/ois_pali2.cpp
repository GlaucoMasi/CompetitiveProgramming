#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct mint{
  static const int mod = 1e9+7;
  int v;

  mint(){ v = 0; }
  mint(long long o){
    v = o%mod;
    if(v < 0) v += mod;
  }

  explicit operator int() const { return v; }

  friend bool operator==(const mint &a, const mint &b){ return a.v == b.v; }
  friend bool operator!=(const mint &a, const mint &b){ return a.v == b.v; }

  mint& operator+=(mint o){
    v = (v+o.v)%mod;
    return *this;
  }

  mint& operator-=(mint o){
    v = (v+mod-o.v)%mod;
    return *this;
  }

  mint& operator*=(mint o){
    v = ((long long)v*o.v)%mod;
    return *this;
  }

  mint& operator/=(mint o){
    v = ((long long)v*inv(o).v)%mod;
    return *this;
  }

  friend mint pow(mint a, long long e){
    if(e == 0) return 1;
    return pow(a*a, e/2)*(e%2 ? a : 1);
  }

  friend mint inv(mint a){ return pow(a, mod-2); }
  friend mint operator+(mint a, mint b){ return a += b; }
  friend mint operator-(mint a, mint b){ return a -= b; }
  friend mint operator*(mint a, mint b){ return a *= b; }
  friend mint operator/(mint a, mint b){ return a /= b; }

  friend istream& operator>>(istream &is, mint &a){ return is >> a.v; }
  friend ostream& operator<<(ostream &os, const mint &a){ return os << a.v; }
};

struct modhash{
  int n, b = 31;
  vector<mint> v, rev, p;

  modhash(vector<int> &data){
    n = data.size();
    v.resize(n), rev.resize(n), p.resize(n);

    p[0] = 1;
    for(int i = 1; i < n; i++) p[i] = p[i-1]*b;

    for(int i = 0; i < n; i++){
      if(i) v[i] += v[i-1]*b;
      v[i] += data[i];
    }

    for(int i = n-1; i >= 0; i--){
      if(i != n-1) rev[i] += rev[i+1]*b;
      rev[i] += data[i];
    }
  }

  mint query(int l, int r){
    mint ans = v[r]-(l ? v[l-1] : 0)*p[r-l+1];
    ans *= p[n-1-(r-l)];
    return ans;
  }

  mint revquery(int l, int r){
    mint ans = rev[l]-(r == n-1 ? 0 : rev[r+1])*p[r-l+1];
    ans *= p[n-1-(r-l)];
    return ans;
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> v(n); for(auto &i : v) cin >> i;

  vector<int> temp(n);
  for(int i = 0; i < n; i++){
    if(v[i] == -1){
      v[i] = 0;
      temp[i] = 1;
    }
  }

  int best = 1;
  auto normal = modhash(v), special = modhash(temp);
  for(int middle = 0; middle < n; middle++){
    int l = 0, r = min(middle+1, n-middle);
    while(l < r-1){
      int m = (l+r)/2;
      if(normal.query(middle, middle+m) == normal.revquery(middle-m, middle)) l = m;
      else r = m;
    }
    
    int idxl = middle-l-1, idxr = middle+l+1;
    if(idxl < 0 || idxr > n-1 || (v[idxl] && v[idxr])) best = max(best, 2*l+1);
    else{
      int x = v[idxl]+v[idxr];

      l = 0, r = min(middle+1, n-middle);
      while(l < r-1){
        int m = (l+r)/2;
        if(normal.query(middle, middle+m)+special.query(middle, middle+m)*x == normal.revquery(middle-m, middle)+special.revquery(middle-m, middle)*x) l = m;
        else r = m;
      }

      best = max(best, 2*l+1);
    }

    l = -1, r = min(middle+1, n-middle-1);
    while(l < r-1){
      int m = (l+r)/2;
      if(normal.query(middle+1, middle+m+1) == normal.revquery(middle-m, middle)) l = m;
      else r = m;
    }

    idxl = middle-l-1, idxr = middle+l+2;
    if(idxl < 0 || idxr > n-1 || (v[idxl] && v[idxr])) best = max(best, 2*l+2);
    else{
      int x = v[idxl]+v[idxr];

      l = -1, r = min(middle+1, n-middle-1);
      while(l < r-1){
        int m = (l+r)/2;
        if(normal.query(middle+1, middle+m+1)+special.query(middle+1, middle+m+1)*x == normal.revquery(middle-m, middle)+special.revquery(middle-m, middle)*x) l = m;
        else r = m;
      }

      best = max(best, 2*l+2);
    }
  }

  cout << best;
}
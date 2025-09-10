#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct mint{
  int v;
  static const int mod = 1e9+7;

  mint(){ v = 0; }
  mint(long long o){ v = (o%mod+mod)%mod; }

  explicit operator int() const { return v; }

  mint& operator+=(mint o){ v = (v+o.v)%mod; return *this; }
  mint& operator-=(mint o){ v = (v+mod-o.v)%mod; return *this; }
  mint& operator*=(mint o){ v = ((long long)v*o.v)%mod; return *this; }
  mint& operator/=(mint o){ v = ((long long)v*inv(o).v)%mod; return *this; }

  friend mint pow(mint a, long long e){ return (e ? 1 : pow(a*a, e/2)*(e%2 ? a : 1)); }
  friend mint inv(mint a){ return pow(a, mod-2); }

  friend mint operator+(mint a, mint b){ return a += b; }
  friend mint operator-(mint a, mint b){ return a -= b; }
  friend mint operator*(mint a, mint b){ return a *= b; }
  friend mint operator/(mint a, mint b){ return a /= b; }

  friend istream& operator>>(istream &is, mint a){ return is >> a.v; }
  friend ostream& operator<<(ostream &os, mint a){ return os << a.v; }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<mint> forw(n), back(n);
  
  for(int i = 0; i < n; i++){
    char c; cin >> c;
    forw[i] = c == 'v';
  }

  for(int i = 0; i < n; i++){
    char c; cin >> c;
    back[i] = c != 'v';
  }

  mint b = 31;
  vector<mint> p(n);
  p[0] = 1; for(int i = 1; i < n; i++) p[i] = p[i-1]*b;

  int k; cin >> k;

  mint goal = 0;
  for(int i = 0; i < k; i++){
    goal *= b;
    char c; cin >> c;
    goal += c == '>';
  }
  
  int ans = 0;
  mint forwhash = 0, backhash = 0;
  for(int i = 0; i < n; i++){
    forwhash *= b;
    forwhash += forw[i];
    if(i-k >= 0) forwhash -= forw[i-k]*p[k];

    backhash *= b;
    backhash += back[n-1-i];
    if(i-k >= 0) backhash -= back[n-i-1+k]*p[k];

    if(i >= k-1){ 
      ans += forwhash.v == goal.v;
      ans += backhash.v == goal.v;
    }
  }

  cout << ans;
}
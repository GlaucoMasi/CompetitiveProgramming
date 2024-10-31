#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int k = 3, maxn = 2e5+5;
int b[k] = {29, 31, 37}, mod[k] = {1000000007, 1000000009, 1000000021};
long long p[k][maxn], fen[k][maxn], inv[k][maxn];

void addfen(int i, int j, long long val){
  while(i < maxn){
    fen[j][i] = (fen[j][i]+val+mod[j])%mod[j];
    i += (i&-i);
  }
}

void addinv(int i, int j, long long val){
  while(i < maxn){
    inv[j][i] = (inv[j][i]+val+mod[j])%mod[j];
    i += (i&-i);
  }
}

long long getfen(int i, int j){
  long long ans = 0;
  while(i > 0){
    ans = (ans+fen[j][i])%mod[j];
    i -= (i&-i);
  }
  return ans;
}

long long getinv(int i, int j){
  long long ans = 0;
  while(i > 0){
    ans = (ans+inv[j][i])%mod[j];
    i -= (i&-i);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  for(int i = 0; i < k; i++) p[i][0] = 1;
  for(int i = 0; i < k; i++) for(int j = 1; j < maxn; j++) p[i][j] = (p[i][j-1]*b[i])%mod[i];

  int n, m; cin >> n >> m;
  string s; cin >> s;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < k; j++){
      addfen(i+1, j, (p[j][i]*(s[i]-'a'+1))%mod[j]);
      addinv(i+1, j, (p[j][n-i-1]*(s[i]-'a'+1))%mod[j]);
    }
  }

  while(m--){
    int t; cin >> t;

    if(t == 1){
      int i; char c;
      cin >> i >> c; i--;

      for(int j = 0; j < k; j++){
        addfen(i+1, j, (mod[j]-p[j][i]*(s[i]-'a'+1))%mod[j]);
        addinv(i+1, j, (mod[j]-p[j][n-i-1]*(s[i]-'a'+1))%mod[j]);
        addfen(i+1, j, (p[j][i]*(c-'a'+1))%mod[j]);
        addinv(i+1, j, (p[j][n-i-1]*(c-'a'+1))%mod[j]);
      }

      s[i] = c;
    }else{
      bool ok = 1;
      int l, r; cin >> l >> r;

      for(int j = 0; j < k; j++){
        long long a = (getfen(r, j)-getfen(l-1, j)+mod[j])%mod[j], b = (getinv(r, j)-getinv(l-1, j)+mod[j])%mod[j];
        a = (a*p[j][max(0, n-r-(l-1))])%mod[j];
        b = (b*p[j][max(0, l-1-(n-r))])%mod[j];
        if(a != b) ok = 0;
      }

      cout << (ok ? "YES\n" : "NO\n");
    }
  }
}
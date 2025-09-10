#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

#define ll long long
#define vll vector<ll>
#define vvll vector<vll>

const int maxn = 100, mod = 1e9+7;
void mult(vvll &a, vvll &b){
  vvll ans(maxn, vll(maxn));
  for(int i = 0; i < maxn; i++){
    for(int j = 0; j < maxn; j++){
      for(int k = 0; k < maxn; k++) ans[i][j] = (ans[i][j] + (a[i][k]*b[k][j])%mod)%mod;
    }
  }
  a = ans;
}

vvll ans(maxn, vll(maxn));
void f(vvll start, int b){
  for(int i = 0; i < maxn; i++) ans[i][i] = 1;
  while(b > 0){
    if(b&1) mult(ans, start);
    mult(start, start);
    b >>= 1;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  vvll start(maxn, vll(maxn));
  int n, m, k; cin >> n >> m >> k;
  for(int i = 0; i < m; i++){
    int a, b; cin >> a >> b;
    start[--a][--b]++;
  }

  f(start, k);
  cout << ans[0][n-1];
}
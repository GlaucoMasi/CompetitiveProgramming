#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

#define pl pair<long long, long long>
#define vpl vector<pl>
#define vvpl vector<vpl>

const int maxn = 100, mod = 1e9+7;
void mult(vvpl &a, vvpl &b){
  vvpl ans(maxn, vpl(maxn, {1e18, 0}));
  for(int i = 0; i < maxn; i++){
    for(int j = 0; j < maxn; j++){
      for(int k = 0; k < maxn; k++){
        if(a[i][k].first+b[k][j].first < ans[i][j].first){
          ans[i][j].first = a[i][k].first+b[k][j].first;
          ans[i][j].second = 0;
        }

        if(a[i][k].first+b[k][j].first == ans[i][j].first) ans[i][j].second = (ans[i][j].second + (a[i][k].second*b[k][j].second)%mod)%mod;
      }
    }
  }

  a = ans;
}

vvpl ans(maxn, vpl(maxn, {1e18, 0}));
void exp(vvpl start, int b){
  for(int i = 0; i < maxn; i++) ans[i][i] = {0, 1};
  while(b > 0){
    if(b&1) mult(ans, start);
    mult(start, start); 
    b /= 2;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int n, m, k; cin >> n >> m >> k;
  vvpl start(maxn, vpl(maxn, {1e18, 0}));
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c; a--; b--;

    if(c < start[a][b].first){
      start[a][b].first = c;
      start[a][b].second = 0;
    }

    if(c == start[a][b].first) start[a][b].second++;
  }

  exp(start, k);
  cout << (ans[0][n-1].second ? ans[0][n-1].first : -1);
}
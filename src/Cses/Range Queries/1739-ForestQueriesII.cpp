#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int maxn = 1001;
int fw[maxn][maxn];

void updy(int x, int y, int k){
  while(y < maxn){
    fw[x][y] += k;
    y += (y&-y);
  }
}

void upd(int x, int y, int k){
  while(x < maxn){
    updy(x, y, k);
    x += (x&-x);
  }
}

int gety(int x, int y){
  int ans = 0;
  while(y > 0){
    ans += fw[x][y];
    y -= (y&-y);
  }
  return ans;
}

int get(int x, int y){
  int ans = 0;
  while(x > 0){
    ans += gety(x, y);
    x -= (x&-x);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, q; cin >> n >> q;
  vector<vector<bool>> v(n, vector<bool>(n));

  for(int i = 1; i <= n; i++){
    string s; cin >> s;
    for(int j = 1; j <= n; j++) if(s[j-1] == '*') v[i-1][j-1] = 1, upd(i, j, 1);
  }

  while(q--){
    int t; cin >> t;

    if(t == 1){
      int x, y; cin >> x >> y;
      upd(x, y, (v[x-1][y-1] ? -1 : 1));
      v[x-1][y-1] = !v[x-1][y-1];
    }else{
      int xa, ya, xb, yb; cin >> xa >> ya >> xb >> yb;
      cout << get(xb, yb) - get(xa-1, yb) - get(xb, ya-1) + get(xa-1, ya-1) << '\n';
    }
  }
}
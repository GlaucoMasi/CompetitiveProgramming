#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, q;
int nxt[200005][30];

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> q;

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    nxt[i][0] = --a;
  }

  for(int j = 1; j < 30; j++) for(int i = 0; i < n; i++) nxt[i][j] = nxt[nxt[i][j-1]][j-1];

  while(q--){
    int x, k; cin >> x >> k; x--;
    for(int j = 0; j < 30; j++) if(k&(1<<j)) x = nxt[x][j];
    cout << x+1 << '\n';
  }
}
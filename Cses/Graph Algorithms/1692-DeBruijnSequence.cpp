#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int k, n;
string ans = "";
vector<vector<pair<int, char>>> g;

void f(int i){
  while(!g[i].empty()){
    auto [j, c] = g[i].back();
    g[i].pop_back();
    ans += c;
    f(j);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> k;
  n = (1<<(k-1));
  g.resize(n);

  if(k == 1){
    cout << "01";
    return 0;
  }

  for(int i = 0; i < n; i++){
    int nxt = (i<<1)%n;
    g[i].push_back({nxt, '0'});
    g[i].push_back({nxt+1, '1'});
  }

  for(int i = 0; i < k-1; i++) ans += '0';
  f(0);
  cout << ans;
}
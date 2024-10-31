#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int ans = 0;
bool v[8][8];
vector<bool> row(8), down(16), up(16);

void f(int i){
  if(i == 8){
    ans++;
    return;
  }

  for(int j = 0; j < 8; j++){
    if(row[j] || up[i-j+8] || down[16-i-j] || v[i][j]) continue;
    row[j] = up[i-j+8] = down[16-i-j] = 1;
    f(i+1);
    row[j] = up[i-j+8] = down[16-i-j] = 0;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  for(int i = 0; i < 8; i++){
    string a; cin >> a;
    for(int j = 0; j < 8; j++) v[i][j] = (a[j] == '*');
  }

  f(0);
  cout << ans;
}
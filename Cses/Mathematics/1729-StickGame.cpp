#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, k;
  cin >> n >> k;
  vector<int> win(n+1);

  vector<int> moves(k);
  for(auto &i : moves) cin >> i;

  for(int i = 1; i <= n; i++) for(auto move : moves) if(move <= i) win[i] |= (!win[i-move]);
  for(int i = 1; i <= n; i++) cout << (win[i] ? 'W' : 'L');
}
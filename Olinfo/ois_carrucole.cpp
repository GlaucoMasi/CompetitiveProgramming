#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, m; fin >> n >> m;
  vector<int> v(n);
  for(auto &i : v) fin >> i;

  int ans = 0;
  int a, b;
  for(int i = 0; i < m; i++){
    fin >> a >> b;
    if(v[a] && v[b]) ans++;
  }

  fout << ans;
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int mod = 1e9+7;
  string a, b;
  fin >> a >> b;

  vector<vector<int>> v(b.size()+1, vector<int>(a.size()+1, 0));
  v[0][0] = 1;

  for(int i = 1; i <= b.size(); i++){
    v[i][0] = 1;

    for(int j = 1; j <= a.size(); j++){
      v[i][j] = v[i-1][j];
      if(a[j-1] == b[i-1]) v[i][j] = (v[i][j] + v[i-1][j-1])%mod;
    }
  }

  fout << v[b.size()][a.size()];
}
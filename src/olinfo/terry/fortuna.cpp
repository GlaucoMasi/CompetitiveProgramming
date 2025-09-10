#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int t; fin >> t;

  for(int tt = 1; tt <= t; tt++){
    int n; fin >> n;

    vector<int> v(n);
    for(auto &i : v) fin >> i;

    vector<int> g(n);
    for(auto &i : g) fin >> i;

    long long sum = 1e10;
    for(int i = 0; i < n; i++){
      long long ans = 0;

      for(int j = 0; j < n; j++){
        int ind = (j + i < n) ? j + i : j + i - n;  
        ans += g[j] * v[ind];
      }

      sum = min(sum, ans);
    } 
  
    fout << "Case #" << tt << ": " << sum << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void solve(int k) {
  int n, q; fin >> n >> q;
  int idx = 0;

  vector<int> v(q); for(auto &i : v) fin >> i;

  int best = 0, ans = 0;

  for(int i = 0; i < q; i++){
    if(idx+v[i] > n){
      ans -= (idx+v[i]-n);
      idx -= (idx+v[i]-n);
    }
    
    idx++;
    ans++;
    best = max(best, ans);
  }

  fout << "Case #" << k << ": " << ans << endl;
}

int main() {
  int t; fin >> t;
  for(int i = 1; i <= t; i++) solve(i);
}
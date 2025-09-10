#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void solve(int k) {
  int n; fin >> n;
  vector<int> v(n); for(auto &i : v) fin >> i;
  v.push_back(-1);

  int kmin = -1, kmax = 1e9+5;

  int sum = -1;
  for(int i = 0; i <= n; i++){
    if(v[i] == -1){
      kmin = max(kmin, sum);
      if(i != n) kmax = min(kmax, sum+v[i+1]);

      sum = -1;
    }else{
      sum += v[i]+1;
    }
  }

  fout << "Case #" << k << ": " << kmin << " " << kmax << endl;
}

int main() {
  int t; fin >> t;
  for(int i = 1; i <= t; i++) solve(i);
}
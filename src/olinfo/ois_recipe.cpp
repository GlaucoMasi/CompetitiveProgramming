#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;

  vector<double> tot(n), temp(n);
  for(int i = 0; i < m; i++){
    double sum = 0;
    for(auto &j : temp){
      cin >> j; sum += j;
    }

    double k = 1e6/sum;
    for(int j = 0; j < n; j++){
      tot[j] += temp[j]*k;
    }
  }

  for(auto j : tot) cout << (int)(j/m) << " ";
}
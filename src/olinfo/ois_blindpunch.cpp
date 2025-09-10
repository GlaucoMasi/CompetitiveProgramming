#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int t; cin >> t;
  while(t--){
    int n, k; cin >> n >> k;
    priority_queue<array<double, 3>> pq;
    
    while(n--){
      double p; cin >> p;
      pq.push({p, 1, p});
    }

    double tot = 0;
    while(k--){
      auto [t, l, p] = pq.top(); pq.pop();
      pq.push({l*(1-p)*p, l*(1-p), p});
      tot += t;
    }

    tot = floor(tot * 1000000) / 1000000;
    cout << fixed << setprecision(6) << tot << '\n';
  }
}
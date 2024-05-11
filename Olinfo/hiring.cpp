#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; long long b;
  fin >> n >> b;

  vector<int> s(n), q(n);
  for(int i = 0; i < n; i++) fin >> s[i] >> q[i];

  vector<pair<double, pair<int, int>>> ratio(n);
  for(int i = 0; i < n; i++) ratio[i] = {(s[i]*1.0)/(q[i]*1.0), {q[i], i}};
  sort(ratio.begin(), ratio.end());

  auto calc = [&](pair<int, double> target) {
    long long tot = 0;
    priority_queue<pair<int, int>> pq;
    pair<int, double> best = {0, -1e9};

    for(int i = 0; i < n; i++){
      pq.push(ratio[i].second); tot += ratio[i].second.first;

      while(tot*1.0*ratio[i].first > b){
        tot -= pq.top().first;
        pq.pop();
      }

      best = max(best, {pq.size(), -tot*1.0*ratio[i].first});

      if(best == target){
        fout << best.first << '\n';
        while(!pq.empty()){
          fout << pq.top().second+1 << '\n';
          pq.pop();
        }
        return best;
      }
    }

    return best;
  };

  calc(calc({-1, -1}));
}
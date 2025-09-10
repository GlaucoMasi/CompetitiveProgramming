#include <bits/stdc++.h>
using namespace std;

struct car{ long long a, b, c; };
vector<pair<long long, int>> dist;
vector<car> v;

int main() {
  int n, q;

  cin >> n; v.resize(n); dist.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i].a >> v[i].b >> v[i].c;

  cin >> q;
  int p, t;
  for(int i = 0; i < q; i++){
    cin >> p >> t; p--;

    for(int j = 0; j < n; j++){
      long long res = v[j].a*t*t + v[j].b*t + v[j].c;
      dist[j] = {-res, j+1};
    }

    nth_element(dist.begin(), dist.begin()+p, dist.end());
    cout << dist[p].second << endl;
  }
}
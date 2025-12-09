#include <bits/stdc++.h>
using namespace std;

int comps;
vector<int> fat, sz;

int get(int i) {
  if(fat[i] == i) return i;
  else return fat[i] = get(fat[i]);
}

void join(int a, int b) {
  a = get(a), b = get(b);
  if(a == b) return;
  if(sz[a] < sz[b]) swap(a, b);
  sz[a] += sz[b]; sz[b] = 0;
  fat[b] = a;
  comps--;
}

int main() {
  string s;
  vector<array<int, 3>> v;
  while(cin >> s) {
    int idx1 = s.find_first_of(','), idx2 = s.find_last_of(',');
    v.push_back({
      stoi(s.substr(0, idx1)),
      stoi(s.substr(idx1+1, idx2-idx1-1)),
      stoi(s.substr(idx2+1))
    });
  }

  int n = v.size();
  fat.resize(n);
  iota(fat.begin(), fat.end(), 0);
  sz.resize(n, 1);
  comps = n;

  auto dist = [&](int i, int j) {
    long long ans = 0;
    for(int k = 0; k < 3; k++) ans += 1LL*(v[i][k]-v[j][k])*(v[i][k]-v[j][k]);
    return ans;
  };

  vector<pair<long long, pair<int, int>>> dists;
  for(int i = 0; i < n; i++) {
    for(int j = i+1; j < n; j++) {
      dists.push_back({dist(i, j), {i, j}});
    }
  }
  sort(dists.begin(), dists.end());

  for(int i = 0; i < dists.size() && comps > 1; i++) {
    auto [a, b] = dists[i].second;
    join(a, b);
    if(comps == 1) cout << 1LL*v[a][0]*v[b][0];
  }
}
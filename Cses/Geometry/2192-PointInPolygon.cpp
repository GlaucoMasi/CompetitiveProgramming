#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<pair<long long, long long>> poly;

long long cross(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> x){
  pair<long long, long long> v1 = {b.first-a.first, b.second-a.second}, v2 = {x.first-a.first, x.second-a.second};
  return v1.first*v2.second-v1.second*v2.first;
}

bool inside(pair<long long, long long> a, pair<long long, long long> b, pair<long long, long long> x){
  vector<pair<long long, long long>> v;
  v.push_back(a);
  v.push_back(b);
  v.push_back(x);
  sort(v.begin(), v.end());
  return (v[1] == x);
}

void solve() {
  long long a, b; cin >> a >> b;

  int wind = 0;
  for(int i = 0; i < n; i++){
    int j = (i+1)%n;

    long long s1 = cross(poly[i], poly[j], {a, b}), s2 = cross(poly[i], poly[j], {2e9, b});
    long long s3 = cross({a, b}, {2e9, b}, poly[i]), s4 = cross({a, b}, {2e9, b}, poly[j]);

    if(!s1 && inside(poly[i], poly[j], {a, b})){
      cout << "BOUNDARY\n";
      return;
    }

    bool intersect = 0;
    if(!s3 && inside({a, b}, {2e9, b}, poly[i]) && max(poly[i].second, poly[j].second) > b) intersect = 1;
    if(!s4 && inside({a, b}, {2e9, b}, poly[j]) && max(poly[i].second, poly[j].second) > b) intersect = 1;
    if(((s1 < 0 && s2 > 0) || (s1 > 0 && s2 < 0)) && ((s3 < 0 && s4 > 0) || (s3 > 0 && s4 < 0))) intersect = 1;

    if(intersect){
      if(poly[i].second < poly[j].second) wind++;
      else if(poly[i].second > poly[j].second) wind--;
    }
  }

  if(!wind) cout << "OUTSIDE\n";
  else cout << "INSIDE\n";
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t; cin >> n >> t;
  poly.resize(n);
  for(auto &[a, b] : poly) cin >> a >> b;

  while(t--) solve();
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ifstream in("ans.txt");
ofstream fout("output.txt");

long long cross(long long a, long long b, long long x, long long y, long long i, long long j){
  pair<long long, long long> v1 = {a-x, b-y}, v2 = {i-x, j-y};
  return v1.first*v2.second-v1.second*v2.first;
}

bool inside(int x, int y, int i, int j, int a, int b){
  vector<pair<int, int>> temp;
  temp.push_back({x, y});
  temp.push_back({i, j});
  temp.push_back({a, b});
  sort(temp.begin(), temp.end());
  return (temp[1] == make_pair(a, b));
}

int a, b, c, d;
int x, y, i, j;
bool solve() {
  cin >> a >> b >> c >> d >> i >> j >> x >> y;

  long long s1 = cross(a, b, x, y, i, j), s2 = cross(c, d, x, y, i, j);
  long long s3 = cross(x, y, a, b, c, d), s4 = cross(i, j, a, b, c, d);

  if(!s1 && inside(x, y, i, j, a, b)) return 1;
  if(!s2 && inside(x, y, i, j, c, d)) return 1;
  if(!s3 && inside(a, b, c, d, x, y)) return 1;
  if(!s4 && inside(a, b, c, d, i, j)) return 1;
  if(((s1 < 0 && s2 > 0) || (s1 > 0 && s2 < 0)) && ((s3 < 0 && s4 > 0) || (s3 > 0 && s4 < 0))) return 1;

  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while(t--) cout << (solve() ? "YES\n" : "NO\n");
}
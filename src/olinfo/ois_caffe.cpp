#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; fin >> n;
  vector<pair<int, int>> v(n); for(auto &[a, b] : v) fin >> a >> b;

  vector<int> comp;
  for(auto &[a, b] : v) comp.push_back(a), comp.push_back(b);
  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end())-comp.begin());
  unordered_map<int, int> m;
  for(int i = 0; i < comp.size(); i++) m[comp[i]] = i;
  
  vector<bool> start(comp.size());
  for(auto &[a, b] : v) start[m[a]] = 1;

  int tot = 0, ans = 0;
  for(int i = 0; i < comp.size(); i++){
    if(start[i]) ans += ++tot;
    else tot--;
  }

  fout << ans;
}
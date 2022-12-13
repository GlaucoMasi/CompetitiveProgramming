#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, k; fin >> n >> k;

  vector<pair<int, pair<int, int>>> v;
  
  int a, b, c;
  for(int i = 0; i < n; i++){
    fin >> a >> b >> c;
    v.push_back({a, {b, c}});
  }

  vector<int> ans;
  for(int i = 0; i < n; i++){
    int comp = v[i].first, solo = v[i].second.first, con = v[i].second.second;

    if(solo > v[comp].second.first || (solo == v[comp].second.first && i > comp)) ans.push_back(solo);
    else ans.push_back(con - (v[comp].second.first-v[comp].second.second));
  }

  sort(ans.begin(), ans.end(), greater<int>());
  
  int tot = 0;
  for(int i = 0; i < k; i++) tot += ans[i];

  fout << tot;
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<pair<int, int>> v;
set<pair<int, int>> taken;

void insert(int i){ taken.insert(v[i]); }

void solve(int k) {
  fin >> n;
  v.clear();
  v.resize(n);
  taken.clear();
  for(auto &i : v) fin >> i.first >> i.second;

  insert(0);

  int ans = 1;
  for(ans; ans < n; ans++){
    auto t = taken.lower_bound(v[ans]);
    pair<int, int> temp = *t;

    if(t == taken.begin()){
      if(temp.first >= v[ans].first && temp.second >= v[ans].second) insert(ans);
      else break;
    }else if(t == taken.end()){
      auto t2 = prev(t);
      temp = *t2;

      if(temp.first <= v[ans].first && temp.second <= v[ans].second) insert(ans);
      else break;
    }else{
      auto t2 = prev(t);
      pair<int, int> temp2 = *t2;

      if(temp.first < v[ans].first || temp.second < v[ans].second) break;
      if(temp2.first > v[ans].first || temp2.second > v[ans].second) break;

      insert(ans);
    }
  }

  fout << "Case #" << k << ": " << ans << endl;
}

int main() {
  int t; fin >> t;
  for(int i = 1; i <= t; i++) solve(i);
}
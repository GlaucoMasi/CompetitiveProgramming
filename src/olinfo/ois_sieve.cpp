#include <bits/stdc++.h>
using namespace std;

int n, m, t, best = 1e9;

unordered_map<bitset<251>, int> memo;
vector<bitset<251>> keep;

int f(bitset<251> left, int curr) {
  if(!left.any()){
    best = min(best, curr);
    return 0;
  }

  if(memo.count(left)){
    best = min(best, curr+memo[left]);
    return memo[left];
  }

  if(clock()-t > 0.25*CLOCKS_PER_SEC){
    cout << best;
    exit(0);
  }

  if(curr+1 >= best) return 1e9;

  vector<pair<int, int>> opt;
  for(int i = 0; i < n; i++) if(left[i]) opt.push_back({(left & keep[i]).count(), i});
  sort(opt.begin(), opt.end());

  int ans = 1e9;
  for(auto [a, b] : opt){
    ans = min(ans, f(left&keep[b], curr+1)+1);
    if(!ans) break;
    if(left.count() - (left&keep[b]).count() == 1) break;
  }
  return memo[left] = ans;
}

int main() {
  t = clock();
  cin >> n >> m;

  vector<int> v(n);
  for(auto &i : v) cin >> i;
  v.resize(unique(v.begin(), v.end())-v.begin());

  n = v.size(); keep.resize(n);
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if((v[i]%v[j]) && (v[j]%v[i])) keep[i].set(j);
    }
  }

  bitset<251> start; for(int i = 0; i < n; i++) start.set(i);
  cout << f(start, 0);
}
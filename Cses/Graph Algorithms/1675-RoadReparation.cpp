#include <bits/stdc++.h>
using namespace std;

vector<int> father, sz;

int get(int a){
  if(a == father[a]) return a;
  else return father[a] = get(father[a]);
}

int main() {
  int n, m; cin >> n >> m;
  priority_queue<pair<int, pair<int, int>>> pq;
  father.resize(n); iota(father.begin(), father.end(), 0);
  sz.resize(n, 1);

  int a, b, c;
  while(m--){
    cin >> a >> b >> c;
    pq.push({-c, {a-1, b-1}});
  }

  int comp = n;
  long long ans = 0;
  while(comp > 1 && !pq.empty()){
    auto curr = pq.top(); pq.pop();

    int a = get(curr.second.first), b = get(curr.second.second);
    if(a != b){
      if(sz[a] < sz[b]) swap(a, b);

      father[b] = a;
      sz[a] += sz[b];
      comp--;

      ans -= curr.first;
    }
  }

  if(comp > 1) cout << "IMPOSSIBLE";
  else cout << ans;
}
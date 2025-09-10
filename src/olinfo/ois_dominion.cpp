#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m, t; cin >> n >> m >> t;
  
  queue<int> q;
  for(int i = 0; i < m; i++){
    int a; cin >> a;
    q.push(a);
  }

  vector<int> f(n), p(n), r(n), v(n);
  for(int i = 0; i < n; i++) cin >> f[i] >> p[i] >> r[i] >> v[i];

  long long value = 0;
  for(int i = 0; i < q.size(); i++){
    value += v[q.front()];
    q.push(q.front());
    q.pop();
  }

  set<pair<int, int>> bs;
  for(int i = 0; i < n; i++) if(f[i]) bs.insert({p[i], i});

  while(t--){
    int a, b, c, d, e;
    a = q.front(); q.pop();
    b = q.front(); q.pop();
    c = q.front(); q.pop();
    d = q.front(); q.pop();
    e = q.front(); q.pop();

    long long R = r[a]+r[b]+r[c]+r[d]+r[e];
    auto card = *prev(bs.upper_bound({R, 1e9}));
    q.push(card.second);
    value += v[card.second];
    f[card.second]--;

    if(!f[card.second]) bs.erase(bs.find(card));

    q.push(a);
    q.push(b);
    q.push(c);
    q.push(d);
    q.push(e);
  }

  cout << value;
}
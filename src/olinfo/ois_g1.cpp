#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, q; cin >> n >> q;
  vector<pair<int, int>> v(n, {-1, -1});

  int last = -1;
  for(int i = 0; i < n; i++){
    int a; cin >> a; a--;

    v[a].first = last;
    if(last != -1) v[last].second = a;
    
    last = a;
  }

  pair<int, int> ans = {0, 0};
  vector<int> num(n);
  while(q--){
    int a; cin >> a; a--;
    int b = v[a].first;

    num[b]++;
    ans = max(ans, {num[b], -b});
    cout << -ans.second+1 << endl;

    if(v[b].first != -1) v[v[b].first].second = a;
    if(v[a].second != -1) v[v[a].second].first = b;
    v[a].first = v[b].first; v[b].first = a;
    v[b].second = v[a].second; v[a].second = b;
  }
}
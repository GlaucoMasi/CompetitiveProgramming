#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int maxn = 2e5+1;
int fen[maxn];

void upd(int i, int k){
  i++;
  while(i < maxn){
    fen[i] += k;
    i += (i&(-i));
  }
}

int get(int i){
  int ans = 0; i++;
  while(i > 0){
    ans += fen[i];
    i -= (i&(-i));
  }
  return ans;
}

int query(int l, int r){ return get(r)-get(l-1); }

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<array<int, 4>> v(n);
  vector<int> comp;

  for(int i = 0; i < n; i++){
    for(int j = 0; j < 4; j++) cin >> v[i][j];
    comp.push_back(v[i][1]);
    comp.push_back(v[i][3]);
  }

  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end())-comp.begin());
  unordered_map<int, int> match;
  for(int i = 0; i < comp.size(); i++) match[comp[i]] = i;
  for(auto &i : v){
    i[1] = match[i[1]];
    i[3] = match[i[3]];
  }

  vector<array<int, 3>> events;
  for(auto [a, b, c, d] : v){
    if(a == c) events.push_back({a, b, d});
    else{
      events.push_back({a, b, -2});
      events.push_back({c, b, -1});
    }
  }

  long long ans = 0;
  sort(events.begin(), events.end());
  for(auto [a, b, c] : events){
    if(c == -2) upd(b, 1);
    else if(c == -1) upd(b, -1);
    else ans += query(b, c);
  }

  cout << ans;
}
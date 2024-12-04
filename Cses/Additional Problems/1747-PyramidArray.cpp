#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int fen[200001];

void add(int i){
  i++;
  while(i <= 2e5){
    fen[i]++;
    i += (i&-i);
  }
}

long long get(int i, int idx){
  i++;

  long long ans = 0;
  while(i > 0){
    ans += fen[i];
    i -= (i&-i);
  }

  return idx-ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> v(n);
  vector<long long> left(n), right(n);
  for(auto &i : v) cin >> i;

  vector<int> comp = v;
  unordered_map<int, int> m;
  sort(comp.begin(), comp.end());
  for(int i = 0; i < n; i++) m[comp[i]] = i;
  for(auto &i : v) i = m[i];

  for(int i = 0; i < n; i++){
    left[i] = get(v[i], i);
    add(v[i]);
  }

  for(int i = 0; i <= 2e5; i++) fen[i] = 0;

  for(int i = n-1; i >= 0; i--){
    right[i] = get(v[i], n-1-i);
    add(v[i]);
  }

  long long ans = 0;
  for(int i = 0; i < n; i++) ans += min(left[i], right[i]);
  cout << ans;
}
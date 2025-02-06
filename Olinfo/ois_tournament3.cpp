#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  vector<pair<int, int>> v;
  int n; cin >> n;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    v.push_back({a, i});
  }

  while(v.size() > 2){
    vector<pair<int, int>> nxt;
    for(int i = 0; i < v.size(); i += 2) nxt.push_back(max(v[i], v[i+1]));
    swap(v, nxt);
  }

  sort(v.begin(), v.end());
  cout << v[1].second << " " << v[0].second;
}
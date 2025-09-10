#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; cin >> n;

  vector<pair<int, bool>> v;
  for(int i = 0; i < n; i++){
    int a, b; cin >> a >> b;

    v.push_back({a, 0});
    v.push_back({b, 1});
  }

  sort(v.begin(), v.end());

  int curr = 0;
  int best = 0;
  for(auto i : v){
    if(i.second) curr--;
    else curr++;

    best = max(best, curr);
  }

  cout << best;
}
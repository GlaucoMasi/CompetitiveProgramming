#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, k; cin >> n >> k;
  string s; cin >> s;

  int i = 0;
  while(i < n && n-i > k){
    pair<char, int> best = {-s[i], i};
    for(int j = 1; j <= k && i+j < n; j++) best = min(best, {-s[i+j], i+j});
    cout << (char)-best.first;
    k -= best.second-i;
    i = best.second+1;
  }
}
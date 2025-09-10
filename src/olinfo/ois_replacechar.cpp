#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  string s; cin >> s;

  vector<int> prev(n);
  vector<pair<int, int>> best(26, {0, -1});
  for(int i = 0; i < n; i++){
    int t = -1;
    for(int j = 0; j <= s[i]-'a'; j++){
      if(best[j].first > t){
        t = best[j].first;
        prev[i] = best[j].second;
      }
    }

    if(best[s[i]-'a'].first < ++t) best[s[i]-'a'] = {t, i};
  }

  auto temp = *max_element(best.begin(), best.end());
  cout << n-temp.first << '\n';
  int i = temp.second;
  vector<bool> main(n);
  while(i != -1){
    main[i] = 1;
    i = prev[i];
  }

  char c = 'a';
  for(int i = 0; i < n; i++){
    if(!main[i]) cout << i << " " << c << '\n';
    else c = max(c, s[i]);
  }
}
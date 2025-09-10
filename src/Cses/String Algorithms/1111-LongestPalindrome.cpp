#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  string temp, s = "+#"; cin >> temp;
  for(auto i : temp) s += i, s += '#'; s += "-";

  int l = 1, r = 1;
  vector<int> ans(s.size()); ans[0] = 1;
  for(int i = 1; i < s.size(); i++){
    ans[i] = min(r-i, ans[l+r-i]);
    while(s[i-ans[i]] == s[i+ans[i]]) ans[i]++;
    if(i+ans[i] > r){
      l = i-ans[i];
      r = i+ans[i];
    }
  }

  int idx = max_element(ans.begin(), ans.end())-ans.begin();
  string best = s.substr(idx-ans[idx]+1, 2*ans[idx]-1);
  for(int i = 0; i < best.size(); i++) if(best[i] != '#') cout << best[i];
}
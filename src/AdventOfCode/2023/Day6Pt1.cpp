#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int conv(string t){
  int ans = 0;
  for(auto c : t) ans = 10*ans+(c-'0');
  return ans;
}

int main() {
  vector<pair<int, int>> v;
  
  string a; fin >> a;
  while(fin >> a){
    if(a == "Distance:") break;
    v.push_back({conv(a), 0});
  }

  for(auto &i : v) fin >> i.second;

  long long ans = 1;
  for(auto [t, d] : v){
    float delta = t*t - d*4;
    delta = sqrt(delta);
    float l = (t-delta)/2, r = (t+delta)/2;

    if(l != (int)l) l = ceil(l);
    else l++;

    if(r != (int)r) r = floor(r);
    else r--;

    int tot = r-l+1; ans *= tot;
  }

  fout << ans;
}
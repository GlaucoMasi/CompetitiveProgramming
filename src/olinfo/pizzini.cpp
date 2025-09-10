#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
unordered_map<string, int> m;
vector<pair<string, string>> v;

int main() {
  fin >> n;
  v.resize(n);
  string ans = "";
  
  for(int i = 0; i < n; i++){
    fin >> v[i].first;
    v[i].second = v[i].first;
    sort(v[i].second.begin(), v[i].second.end());
    
    if(!m.count(v[i].second)) m[v[i].second] = 1;
    else m[v[i].second]++;
  }

  for(auto i : v) ans += i.first[m[i.second]-1];

  fout << ans;
}
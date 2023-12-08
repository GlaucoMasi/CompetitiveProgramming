#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  string inst; fin >> inst;
  
  string a;
  map<string, pair<string, string>> m;

  while(getline(fin, a)){
    if(a.empty()) continue;
    string start = a.substr(0, 3), left = a.substr(7, 3), right = a.substr(12, 3);
    m[start] = {left, right};
  }

  long long ans = 1;

  for(auto i : m) if(i.first[2] == 'A'){
    string t = i.first;
    for(long long d = 0; 1; d++){
      if(t[2] == 'Z'){
        ans = (ans*d)/__gcd(ans, d);
        break;
      }

      if(inst[d%inst.size()] == 'L') t = m[t].first;
      else t = m[t].second;
    }
  }

  fout << ans;
}
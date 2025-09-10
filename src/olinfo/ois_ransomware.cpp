#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;
  vector<string> v(n);
  for(int i = 0; i < n; i++) fin >> v[i];

  map<string, char> m;
  for(int i = 0; i < 10; i++){
    string a; fin >> a;
    m[a] = i + '0';
  }

  for(int i = 0; i < n; i++){
    string t = v[i];
    string ans = "";

    for(int j = 0; j < t.size(); j++){
      string look = "";
      look += t[j];

      while(!m.count(look)){
        j++;
        look += t[j];
      }

      ans += m[look];
    }

    fout << ans << endl;
  }
}
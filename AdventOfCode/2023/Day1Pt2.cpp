#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  map<string, int> m;
  m["one"] = 1;
  m["two"] = 2;
  m["three"] = 3;
  m["four"] = 4;
  m["five"] = 5;
  m["six"] = 6;
  m["seven"] = 7;
  m["eight"] = 8;
  m["nine"] = 9;
  
  string a; int ans = 0;
  while(fin >> a){
    for(int i = 0; i < a.size(); i++){
      int c = a[i]-'0';
      if(c >= 0 && c <= 9){
        ans += 10*c;
        break;
      }

      bool found = 0;
      for(auto j : m){
        if(i+j.first.size()-1 < a.size() && a.substr(i, j.first.size()) == j.first){
          ans += 10*j.second;
          found = 1;
          break;
        }
      }
      if(found) break;
    }

    for(int i = a.size()-1; i >= 0; i--){
      int c = a[i]-'0';
      if(c >= 0 && c <= 9){
        ans += c;
        break;
      }

      bool found = 0;
      for(auto j : m){
        if(i+j.first.size()-1 < a.size() && a.substr(i, j.first.size()) == j.first){
          ans += j.second;
          found = 1;
          break;
        }
      }
      if(found) break;
    }

    cout << ans << '\n';
  }

  fout << ans;
}
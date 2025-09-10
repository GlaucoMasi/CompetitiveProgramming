#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  string a; vector<string> v;
  while(fin >> a) v.push_back(a+'.'); a += '.';
  
  int ans = 0;
  for(int j = 0; j < v.size(); j++){
    int curr = 0; bool ok = 0;

    for(int i = 0; i < a.size(); i++){
      int c = v[j][i]-'0';
      if(c > 9 || c < 0){
        ans += ok*curr;
        ok = 0; curr = 0;
        continue;
      }

      curr *= 10; curr += c;
      
      if(j > 0){
        if(i > 0 && v[j-1][i-1] != '.' && ((v[j-1][i-1]-'0') < 0 || (v[j-1][i-1]-'0') > 9)) ok = 1;
        if(v[j-1][i] != '.' && ((v[j-1][i]-'0') < 0 || (v[j-1][i]-'0') > 9)) ok = 1;
        if(i+1 < a.size() && v[j-1][i+1] != '.' && ((v[j-1][i+1]-'0') < 0 || (v[j-1][i+1]-'0') > 9)) ok = 1;
      }

      if(j+1 < v.size()){
        if(i > 0 && v[j+1][i-1] != '.' && ((v[j+1][i-1]-'0') < 0 || (v[j+1][i-1]-'0') > 9)) ok = 1;
        if(v[j+1][i] != '.' && ((v[j+1][i]-'0') < 0 || (v[j+1][i]-'0') > 9)) ok = 1;
        if(i+1 < a.size() && v[j+1][i+1] != '.' && ((v[j+1][i+1]-'0') < 0 || (v[j+1][i+1]-'0') > 9)) ok = 1;
      }

      if(i > 0 && v[j][i-1] != '.' && ((v[j][i-1]-'0') < 0 || (v[j][i-1]-'0') > 9)) ok = 1;
      if(i+1 < a.size() && v[j][i+1] != '.' && ((v[j][i+1]-'0') < 0 || (v[j][i+1]-'0') > 9)) ok = 1;
    }
  }

  fout << ans;
}
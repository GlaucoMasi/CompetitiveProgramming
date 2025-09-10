#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

string s;

bool pah(int i){
  if(s[i+1] == 'a')
    if(s[i+2] == 'H')
      return true;

  return false;
}

bool tunz(int i){
  if(s[i+1] == 'u')
    if(s[i+2] == 'N')
      if(s[i+3] == 'Z')
        return true;
      

  return false;
}

int main() {
  int n; fin >> n;
  fin >> s;
  string ans = "";
  bool spazio = 0;

  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'P')
      if(pah(i)){
        i += 2;
        if(spazio) ans += " ";
        spazio = 0;
        continue;
      }
  
    if(s[i] == 'T')
      if(tunz(i)){
          i += 3;
          if(spazio) ans += " ";
          spazio = 0;
          continue;
        }

    ans += s[i];
    spazio = 1;
  }

  fout << ans;
}
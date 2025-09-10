#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;
  string s; fin >> s;

  int i = 0, j = 1;
  while(j < s.size()){
    if(s[j] > s[i]) i = j;
    else if(s[j] == s[i]){
      int a = i, b = j;

      while(s[a] == s[b] && b < s.size()){ a++; b++; }

      if(b == s.size() || s[a] > s[b]) j = b;
      else i = j;
    }
    
    j++;
  }

  fout << i;
}
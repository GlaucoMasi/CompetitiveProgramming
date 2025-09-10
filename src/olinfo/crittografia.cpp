#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, l; fin >> n >> l;
  string s; fin >> s;

  int found = 0;
  vector<char> v(n, '$');

  for(int i = 0; i < l; i++){
    if(s[i] == s[s.size()-i-1]) continue;

    int index; char letter;
    if(s[i] < s[s.size()-i-1]) index = (s[i]-'0'), letter = s[s.size()-i-1];
    else index = (s[s.size()-i-1]-'0'), letter = s[i];
    
    if(v[index] == '$') found++;
    else if(v[index] != letter){
      fout << "impossibile";
      exit(0);
    }

    v[index] = letter;
  }

  if(found != n) fout << "impossibile";
  else for(auto i : v) fout << i;
}
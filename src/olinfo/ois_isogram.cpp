#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, tot;

void compute(string s){
  map<char, int> m;

  for(auto c : s){
    if(c <= 90) c += ' ';
    if(!(c >= 'a' && c <= 'z')) continue;

    if(m.count(c)) m[c]++;
    else m[c] = 1;

    if(m[c] == 3){
      tot--;
      return;
    }
  }
  
  return;
}

int main() {
  fin >> n;
  tot = n;

  string s;
  while(getline(fin, s)) compute(s);

  fout << tot;
}
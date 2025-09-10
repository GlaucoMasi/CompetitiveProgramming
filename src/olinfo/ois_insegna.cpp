#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

string a, b;

bool check(int i){
  for(int j = 0; j < b.size(); j++){
    if(i == a.size()) i = 0;

    if(a[i] != b[j]) return 0;
    
    i++;
  }

  return 1;
}

int main() {
  int n; fin >> n;
  fin >> a >> b;
  bool yes = 0;
  
  for(int i = 0; i < a.size(); i++){
    if(a[i] == b[0])
      if(check(i)){
        yes = 1;
        break;
      }
  }

  fout << yes;
}
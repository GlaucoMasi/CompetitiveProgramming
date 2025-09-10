#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int a; fin >> a;

  map<int, bool> map;

  long long int b;
  string s = "Ok";
  for(int i = 0; i < a; i++){
    fin >> b;
    if(map.count(b)){
      s = "Impossible";
    }

    map[b] = 1;
  }

  fout << s;
}
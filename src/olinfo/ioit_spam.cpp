#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int b, g, n;
  set<string> bad, good;

  fin >> b;
  for(int i = 0; i < b; i++){
    string a; fin >> a;
    bad.insert(a);
  }

  fin >> g;
  for(int i = 0; i < g; i++){
    string a; fin >> a;
    good.insert(a);
  }

  fin >> n;
  int cGood = 0, cBad = 0;
  while(n--){
    int k; fin >> k;
    bool isBad = 0, isGood = 0;
    while(k--){
      string a; fin >> a;
      if(good.count(a)) isGood = 1;
      if(bad.count(a)) isBad = 1;
    }

    cGood += isGood && !isBad;
    cBad += !isGood & isBad;
  }

  fout << cBad << " " << cGood;
}
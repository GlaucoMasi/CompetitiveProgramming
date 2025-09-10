#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int h1, m1, h2, m2;

void solve(int a){
  fout << a / 60 << " " << a % 60;
  return;
}

int main() {
  fin >> h1 >> m1 >> h2 >> m2;

  int def1 = h1*60 + m1;
  int def2 = h2*60 + m2;

  if(def1 <= def2) solve(def2 - def1);
  if(def1 > def2) solve(24*60 - def1 + def2);

  return 0;
}
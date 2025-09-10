#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;

  int tot = -1;
  int a, b;

  fin >> b;
  
  for(int i = 0; i < n-1; i++){
    a = b;
    fin >> b;

    tot = max(tot, abs(b - a));
  }

  fout << tot;
}
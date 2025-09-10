#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int t; fin >> t;

  for(int tt = 1; tt <= t; tt++){
    int a1, a2, b1, b2, c1, c2;
    fin >> a1 >> a2 >> b1 >> b2 >> c1 >> c2;
    fout << "Case #" << tt << ": " << min(a2, min(b2, c2)) - max(a1, max(b1, c1)) << endl;
  }  
}
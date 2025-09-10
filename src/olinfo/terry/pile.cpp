#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int t; 
  fin >> t;

  for(int i = 0; i < t; i++){
    int n;
    fin >> n;

    int tot = 0;
    for(int j = 0; j < n; j++){
      int a, b, c;
      fin >> a >> b >> c;

      int maggior = max(a, b);
      maggior = max(maggior, c);

      tot = tot + maggior;
    }

    fout << "Case #" << i+1 << ": " << tot << endl;
  }
}
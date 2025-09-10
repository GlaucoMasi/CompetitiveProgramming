#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n1, n2, a;
  int tot = 0;
  vector<bool> v(1e9);

  fin >> n1 >> n2;
  for(int i = 0; i < n1; i++){
    fin >> a;
    v[a] = 1;
  }

  for(int i = 0; i < n2; i++){
    fin >> a;
    if(v[a]) tot++;
  }

  fout << tot;
}
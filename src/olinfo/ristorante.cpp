#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, d; fin >> n >> d;
  vector<int> v(n);
  int somma = 0;

  for(auto &i : v){
    fin >> i;
    somma += i;
  }

  int m;
  fin >> m;

  if(m >= n) fout << somma - d*(m-n);
  else{
    sort(v.begin(), v.end());
    somma = 0;
    for(int i = 0; i < m; i++) somma += v[i];
    fout << somma;
  }
}
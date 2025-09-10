#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;

int f(int i){
  if(i == 1) return 1;

  if(i % 2 == 0) return f(i/2) + 1;
  else return f(i*3 + 1) + 1;
}

int main() {
  fin >> n;
  fout << f(n);
}
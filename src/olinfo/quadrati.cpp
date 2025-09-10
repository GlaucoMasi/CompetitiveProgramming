#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

long long int a, b;

int main() {
  fin >> a >> b;

  int a2, b1;
  float a1;
  a1 = sqrt(a); b1 = sqrt(b); a2 = sqrt(a);

  int tot = b1 - a2;
  if(a1 == a2) tot++;

  fout << tot; 
}
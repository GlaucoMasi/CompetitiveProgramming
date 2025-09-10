#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, m, k;
  fin >> n >> m >> k;
  fout << n-(int)sqrt(n);
}
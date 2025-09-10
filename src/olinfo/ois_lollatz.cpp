#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n; fin >> n;
  while(n%10) n = (n*(n%10-1))/2;
  fout << n;
}
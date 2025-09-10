#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; string s;
  fin >> n >> s;

  int a = 0;
  for(int i = 1; i < n; i += 4) a += s[i] == '+';
  fout << min(a, n/4-a);
}
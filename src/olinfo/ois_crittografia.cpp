#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long n; fin >> n;
  string str = to_string(n);
  reverse(str.begin(), str.end());
  fout << n + stoi(str);
}
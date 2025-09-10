#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;
  int ans = 0;
  
  for(int i = 0; i <= 30; i++) ans += ((n & (1<<i)) != 0);
  
  fout << ans;
}
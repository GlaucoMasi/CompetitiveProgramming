#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, m; fin >> n >> m;

  int curr = 0, last = 0, needed = 0;
  for(int i = 0; i < n; i++){
    int a, b; fin >> a >> b;

    curr -= a-last-1;
    needed = min(needed, curr);
    curr += b-a+1;

    if(i == n-1) curr -= m-b;
    last = b;
    
  }

  fout << -min(curr, needed)+1;
}
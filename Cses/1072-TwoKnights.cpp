#include <bits/stdc++.h>
using namespace std;

long long tot;

void calc(int s){
  tot = 0;

  tot += (s-2)*(s-2)*(s*s-9);
  tot += (s-2)*4*(s*s-7);
  tot += (s-1)*4*(s*s-5);
  tot += 8*(s*s-4);
  tot += 4*(s-s-3);

  cout << tot << endl;
}

int main() {
  int t; cin >> t;

  for(int i = 0; i < t; i++) calc(i+1);
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

long long stima(int n, int h[]){
  for(int i = 0; i < n; i++) h[i] -= i;
  nth_element(h, h+n/2, h+n);

  long long ans = 0;
  for(int i = 0; i < n; i++) ans += abs(h[i]-h[n/2]);
  return ans;
}
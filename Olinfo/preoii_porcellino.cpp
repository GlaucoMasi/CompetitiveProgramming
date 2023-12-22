#include <bits/stdc++.h>
using namespace std;

bool chiedi(int X);

int indovina() {
  chiedi(0);
  
  int ans = 0;
  for(int i = 0; i < 31; i++) ans += chiedi(1<<i)*(1<<i);

  return ans;
}
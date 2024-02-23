#include <bits/stdc++.h>
using namespace std;

int pollice_verde(int n, vector<int> h){
  int ans = 0;
  for(int i = 0; i < n; i++) ans += ((!i || h[i-1] <= h[i]) && (i == n-1 || h[i+1] <= h[i]));
  return ans;
}
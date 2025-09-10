#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n; long long x;
int l = 0, r = 0, mid = 0;
long long costo = 0; int ans = 0;
vector<long long> v;

bool check() {
  int best = l + (r-l)/2;

  while(mid < best){
    costo += (v[mid+1]-v[mid])*(2*mid-l-r+1);
    mid++;
  }
  
  ans = max(ans, (costo <= x)*(r-l+1));
  return (costo <= x);
}

int main() {
  fin >> n >> x;
  v.resize(n);
  for(auto &i : v) fin >> i;

  while(r < n-1){
    while(check() && r < n-1){
      r++;
      costo += v[r]-v[mid];
    }

    while(!check() && l < r){
      costo -= v[mid]-v[l];
      l++;
    }
  }

  fout << ans;
}
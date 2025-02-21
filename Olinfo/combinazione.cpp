#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; fin >> n;
  vector<long long> v(n); for(auto &i : v) fin >> i;
  
  long long l = -2e18, r = 2e18;
  for(int i = 0; i < n-1; i++){
    long long L = (2LL*v[i]-v[i+1]), R = v[i];
    l = max(l, L), r = min(r, R);
    l = 2LL*v[i]-l; r = 2LL*v[i]-r;
    
    if(l < r){
      fout << 0;
      return 0;
    }
    
    swap(l, r);
  }

  fout << r-l+1;
}
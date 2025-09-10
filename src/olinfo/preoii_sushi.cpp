#include <bits/stdc++.h>
using namespace std;

int sushi(int n, int k, vector<int> a){
  int l = 0, r = k+2; int log = log2(k)+1;

  while(l < r-1){
    int m = (l+r)/2;
    bitset<100001> b; b.set(0);

    int tot = m;
    for(int j = 1; 1; j *= 2){
      if(tot < j){
        for(auto i : a) b |= (b<<(i*tot));
        break;
      }

      for(auto i : a) b |= (b<<(i*j));
      tot -= j;
    }

    if(b[k]) r = m;
    else l = m;
  }

  if(l == k+1) return -1;
  else return l+1;
}
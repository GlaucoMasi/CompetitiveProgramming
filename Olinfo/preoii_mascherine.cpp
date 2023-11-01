#include <bits/stdc++.h>
using namespace std;

void riprogramma(int n, int k, vector<int>& v){
  for(auto &i : v) i--;

  if(k >= 3){
    for(int i = 1; i < n; i++){
      if(v[i-1] == v[i]){
        int curr = (v[i-1]+1)%k;
        if(i != n-1 && v[i+1] == curr) curr = (curr+1)%k;
        v[i] = curr;
      }
    }
  }else{
    int count = 0;
    for(int i = 0; i < n; i++) if((!(i%2) && v[i] == 0) || (i%2 && v[i] == 1)) count++;

    v = vector<int>(n, 0);
    for(int i = (count > n-count); i < n; i += 2) v[i] = 1;
  }

  for(auto &i : v) i++;
}
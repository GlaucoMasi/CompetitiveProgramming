#include <bits/stdc++.h>
using namespace std;

bool test(int k, int R, int A[], int B[]){
  int t = -k;

  for(int i = 0; i < R; i++){
    t = max(A[i], t+k);
    if(t > B[i]) return 0;
  }

  return 1;
}

void build(int k, int R, int A[], int T[]){
  int t = -k;

  for(int i = 0; i < R; i++){
    t = max(A[i], t+k);
    T[i] = t;
  }
}

void pianifica(int R, int A[], int B[], int T[]){
  int l = 0, r = 1e9;
  for(int i = 0; i < R-1; i++) r = min(r, B[i+1]-A[i]);

  while(l < r){
    int m = l + (r-l+1)/2;

    if(test(m, R, A, B)){
      l = m;
    }else{
      r = m-1;
    }
  }

  build(l, R, A, T);
}
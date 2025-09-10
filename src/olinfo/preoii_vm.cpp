#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

long long aggiorna(int N, vector<int> A, vector<int> B){
  long long int tot = 0;

  for(auto i = N-2; i >= 0; i--){
    long long int a = A[i+1] - A[i];
    tot += a / B[i];
    A[i] = A[i+1] - (a % B[i]);
  }

  return tot;
}
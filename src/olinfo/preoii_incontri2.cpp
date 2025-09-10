#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

bool visita(int N, int A[]){
  for(int i = 1; i < N; i++) A[i] += A[i-1];

  for(int i = 1; i < N; i++){
    if(A[i-1] == A[N-1] - A[i]) return 1;
  }

  return 0;
}
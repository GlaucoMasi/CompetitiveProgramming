#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int ContaOperazioni(int N, int K, int* secchi){
  int needed = 0, surplus = 0;

  for(int i = 0; i < N; i++){
    if(secchi[i] > K) surplus += secchi[i]-K;
    else if(secchi[i] < K) needed += K-secchi[i];
  }

  return min(needed, surplus) + abs(surplus-needed);
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int presta(int N, int C, vector<int> P){
  sort(P.begin(), P.end(), greater<int>());

  int i = 0;
  while(C > 0){
    C -= P[i];
    i++;
  }
  
  return i;
}
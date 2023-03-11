#include <bits/stdc++.h>
using namespace std;

vector<long long> calcola(int T, int M, vector<long long> S,
vector<long long> P){
  vector<long long> R(M);
  vector<long long> cum(T), num(T);
  cum[0] = 0;
  num[0] = S[0];

  for(int i = 1; i < T; i++){
    num[i] = num[i-1] + S[i];
    cum[i] = cum[i-1] + S[i] * i;
  }

  for(int i = 0; i < M; i++){
    long long spazio = P[i];
    int index = lower_bound(cum.begin(), cum.end(), spazio) - cum.begin();
    
    if(cum[index] == spazio) R[i] = num[index];
    else if(index == T) R[i] = num[index-1];
    else R[i] = num[index-1] + (spazio-cum[index-1])/index;
  }

  return R;
}
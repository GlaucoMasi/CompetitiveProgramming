#include <bits/stdc++.h>
using namespace std;

vector<long long> sum;

bool check(int i){
  int last = -1, next; 
  long long inc = sum[sum.size()-1] / i, search = inc;

  for(int j = 1; j < i; j++){
    if(last == sum.size()-1) return 0;
    next = find(sum.begin()+last+1, sum.end(), search) - sum.begin();

    if(next >= sum.size()-1) return 0;
    
    last = next;
    search += inc;
  }

  return 1;
}

int taglia(int N, vector<int> B){
  sum.resize(N);
  sum[0] = B[0];
  for(int i = 1; i < sum.size(); i++) sum[i] = B[i] + sum[i-1];

  long long n = abs(sum[N-1]);

  if(!n){
    if(find(sum.begin(), sum.end(), 0) - sum.begin() < N-1) return 2;
    else return -1;
  }else{
    for(int i = 2; i*i <= n; i++){
      if(n % i == 0)
        if(check(i)) return i;
      
      while(n % i == 0) n /= i;
    }

    if(n > 1)
      if(check(n)) return n;
  }

  return -1;
}
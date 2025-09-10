#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, mag;
vector<int> fibm;

vector<bool> check;

void fib(int i){
  fibm[i] = fibm[i-1] + fibm[i-2];

  if(fibm[i] > n){ 
    mag = i-1;
    
    return;
  } else fib(i+1);
}

int main() {
  fin >> n;

  fibm.resize(n);

  fibm[0] = fibm[1] = 1;

  fib(2);

  check.resize(mag+1, 0);
  check[mag] = 1;
  int tot = fibm[mag];

  for(int i = mag-1; i >= 0; i--){
    if(tot == n){
      for(auto e : check){ 
        fout << e;
      }
      break;
    }

    if(tot + fibm[i] <= n){
      tot += fibm[i];
      check[i] = true;
    }
  }
}
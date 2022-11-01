#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

bool associabili(int N, int voti2[], int voti5[]){
  vector<int> seconda(10, 0), quinta(10, 0);

  for(int i = 0; i < N; i++){
    seconda[voti2[i]-1]++;
    quinta[voti5[i]-1]++;
  }

  int j = 0;
  for(int i = 0; i < 10; i++){
    if(!seconda[i]) continue;

    while(!quinta[j]) j++;

    if(j <= i) return 0;

    if(seconda[i] == quinta[j]){
      j++;
    }else if(seconda[i] > quinta[j]){
      seconda[i] -= quinta[j];
      j++; i--;
    }else if(quinta[j] > seconda[i]){
      quinta[j] -= seconda[i];
    }
  }

  return 1;
}
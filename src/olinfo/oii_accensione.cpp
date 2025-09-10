#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void Accendi(int N, int acceso[], int pulsante[]){
  for(int i = N; i > 0; i--){
    for(int k = i*2; k <= N; k += i)
      if(pulsante[k]) acceso[i] = !acceso[i];
  
    if(!acceso[i]){
      acceso[i] = 1;
      pulsante[i] = 1;
    }
  }
}
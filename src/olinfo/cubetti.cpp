#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void Vernicia(int indice, int colore);

void Diversifica(int N, int colore[]){
  vector<pair<bool, bool>> taken(N);

  for(int i = 0; i < N; i++) taken[colore[i]-1].first = 1;

  int k = 0;
  for(int i = 0; i < N; i++){
    if(taken[colore[i]-1].second){
      while(taken[k].first) k++;
      taken[k].first = 1;
      Vernicia(i, k+1);
    }else taken[colore[i]-1].second = 1;
  }
}
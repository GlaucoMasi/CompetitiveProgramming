#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int N;
  fin >> N;

  int piugrande = -100000;

// for(  ;  ;  ) va avanti finchÃ¨ la condizione Ã¨ vera
  for(int i = 0; i < N; i = i+1){
    int numero;
    fin >> numero;

    if(numero > piugrande){
      piugrande = numero;
    }
  }
  
  fout << piugrande;

}
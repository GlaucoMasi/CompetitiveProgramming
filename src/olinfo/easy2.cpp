#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
  int N = 1;
  fin >> N;

  int mag = -1;
  
  for(int i=0; i<N; i = i+1){
    int a,b;
    fin >> a >> b;
    int somma = a+b;
    
    if(somma % 2 == 0 && somma > mag){
      mag = somma;
    }
  }

  fout << mag;
  
}
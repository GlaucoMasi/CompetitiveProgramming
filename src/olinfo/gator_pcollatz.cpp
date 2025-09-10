#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n1, n2;
int tot = 0;
int col, pol;

int main(){
  fin >> n1 >> n2;

  for(int i = n1; i <= n2; i++){
    col = i;
    pol = i;

    while(1){
      if(col == 1){
        break;
      }

      if(pol == 1){
        tot++;
        break;
      }

      col = (col % 2 == 0) ? col/2 : 3*col+1;
      pol = (pol % 2 == 0) ? pol/2 : 5*pol+1;
    }
  }

  fout << tot;
}
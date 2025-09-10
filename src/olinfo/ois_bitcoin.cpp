#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  fout << setprecision(8) << fixed;

  int n, ex;
  double bitcoin = 1;
  double euro = 0;
  fin >> n >> ex;
  int a; fin >> a;

  bool up = a > 0;

  if(!up){
    euro = bitcoin * ex;
    bitcoin = 0;
  }
  
  ex += a;

  for(int i = 1; i < n; i++){
    fin >> a;

    if(up){
      if(a >= 0) ex += a;
      else{
        if(bitcoin != 0){
          euro = bitcoin * ex;
          bitcoin = 0;
        }

        up = 0;
        ex += a;
      }
    }else{
      if(a <= 0) ex += a;
      else{
        if(euro != 0){
          bitcoin = euro;
          bitcoin /= ex;
          euro = 0;
        }

        up = 1;
        ex += a;
      } 
    }
  }

  fout << euro + bitcoin * ex;
}
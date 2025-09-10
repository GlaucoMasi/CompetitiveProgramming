#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, tot, curr;

int main() {
  fin >> n;
  n++;

  curr = 1e8;
  tot = 0;

  for(int i = 0; i < n-1; i++){
    int temp; 
    fin >> temp;

    if(temp < curr + 1){
      curr = temp;
      tot += curr;
    }else{
      curr++;
      tot += curr;
    }
  }

  fout << tot;
}
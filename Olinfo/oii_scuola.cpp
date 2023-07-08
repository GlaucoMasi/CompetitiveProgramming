#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, p;

void uno(){
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++) fout << j+1 << " " << (j+i)%n+1 << " ";
    fout << '\n';
  }
}

void due(){
  for(int i = 1; i < n; i++){
    for(int j = 0; j < n; j++) if((j^i) > j) fout << j+1 << " " << (j^i)+1 << " ";
    fout << '\n';
  }
}

int main() {
  fin >> n >> p;

  if(p == 1) uno();
  else due();
}
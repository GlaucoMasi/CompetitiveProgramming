#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  fin.tie(0);
  fin.sync_with_stdio(0);

  int n;
  fin >> n;

  int last = -1;
  long long int costo = 0;

  for(int i = 0; i < n; i++){
    int curr;
    fin >> curr;

    if(curr > last){
      costo += curr;
      last = curr;
    }
  }

  fout << costo;
}
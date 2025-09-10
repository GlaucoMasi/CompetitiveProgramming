#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n;
  fin >> n;

  int tot = 0;
  int a = 0;
  int b;
  for(int i = 0; i < n; i++){
    fin >> b;
    
    if(b == -1) tot += a;
    else{  
      tot += b;
      a = b;
    }
  }

  fout << tot;
}
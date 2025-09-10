#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, k; fin >> n >> k;

  string a;
  fin >> a; fout << a;
  int sz = a.size(); n--;
  while(n--){
    fin >> a;
    
    if(sz+a.size()+1 <= k){
      fout << " " << a;
      sz += a.size()+1;
    }else{
      fout << endl << a;
      sz = a.size();
    }
  }
}
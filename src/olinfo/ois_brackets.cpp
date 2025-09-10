#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main(){
  int t; fin >> t;

  while(t--){
    int n, k; fin >> n >> k;
    
    vector<int> pila;
    for(int i = 0; i < n; i++){
      int par; fin >> par;

      if(!pila.empty() && pila.back() == par) pila.pop_back();
      else pila.push_back(par);
    }

    fout << pila.empty() << endl;
  }
}
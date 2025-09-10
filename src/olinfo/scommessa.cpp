#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;

int main() {
  fin >> n;

  vector<int> v(n);
  vector<int> lista;
  for(int i = 0; i < n; i++) fin >> v[i];

  for(int i = 0; i < n; i++){
    int dis = 0;
    int par = 0;
    
    for(int y = 0; y < i; y++){
      if(v[y] % 2 == 0) par++;
      else dis++;
    }

    if(par == dis){
      dis = 0;
      par = 0;

      for(int y = i+1; y < n; y++){
        if(v[y] % 2 == 0) par++;
        else dis++;
      }

      if(par == dis) lista.push_back(v[i]); 
    }
  }

  fout << lista.size() << endl;
  for(auto e : lista) fout << e << " ";
}
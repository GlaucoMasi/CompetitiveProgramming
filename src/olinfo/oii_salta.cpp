#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<int> v;
vector<bool> check;

int main() {
  fin >> n;
  n++;
  
  v.resize(n);
  check.resize(n, false);
  check[0] = true;

  for(int i = 1; i < n; i++) fin >> v[i];
  
  int i = 1;
  while(!check[i]){
    if(i >= n) break;

    check[i] = true;
  
    i = ((i + v[i]) % (n - 1)) + 1;
  }

  int conto = 0;
  for(int i = 1; i < n; i++) if(!check[i]) conto++;
  fout << conto << endl;
  for(int i = 1; i < n; i++) if(!check[i]) fout << i << " ";
}
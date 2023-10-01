#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> curr;

void f(int rim, int max){
  if(!rim){ 
    for(auto i : curr) fout << i << " ";
    fout << '\n';
  }
  
  for(int i = 1; i <= min(rim, max); i++){
    curr.push_back(i);
    f(rim-i, i);
    curr.pop_back();
  }
}

int main() {
  int n; fin >> n;
  f(n, n);
}
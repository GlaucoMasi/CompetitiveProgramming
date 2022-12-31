#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, k;
vector<int> v, l, ans;
vector<bool> idx, elem;

void f(int i){
  idx[i] = 1;
  elem[v[i]-1] = 1;

  for(auto j : l){
    if(i+j < n && !idx[i+j]) f(i+j);
    if(i-j >= 0 && !idx[i-j]) f(i-j);
  }
}

int main() {
  fin >> n >> k;
  v.resize(n); for(auto &i : v) fin >> i;
  l.resize(k); for(auto &i : l) fin >> i;
  ans.resize(n, -1);

  for(int i = 0; i < n; i++){
    if(ans[i] == -1){
      idx.clear(); idx.resize(n);
      elem.clear(); elem.resize(n);
    
      f(i);
      
      int a = 0, b = 0;
      while(1){
        while(!idx[a] && a < n) a++;
        while(!elem[b] && b < n) b++;

        if(a == n) break;

        ans[a] = b+1;
        a++; b++;
      }
    }
  }

  for(int i = 0; i < n; i++) fout << (ans[i] == -1 ? v[i] : ans[i]) << " ";
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;
  vector<bool> ans(100);
  ans[0] = 1;

  int a;
  for(int i = 0; i < n; i++){
    fin >> a;

    for(int j = a; j < 100; j++){
      if(ans[j-a]) ans[j] = 1;
    }
  }

  for(int i = 99; i >= 0; i--){
    if(!ans[i]){
      fout << i;
      break;
    }
  }
}
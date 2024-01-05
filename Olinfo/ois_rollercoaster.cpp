#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int solve() {
  int n; fin >> n;
  vector<int> v(n); for(auto &i : v) fin >> i;

  int status = 0, prog, start, height;
  for(int i = 0; i < n-1; i++){
    if(i != n-2 && v[i+1]-v[i] > 0 && v[i+1]-v[i] == v[i+2]-v[i+1]){
      prog = v[i+1]-v[i];
      status = 1;
    }

    if(status == 0){
      if(v[i+1] < v[i]){
        start = v[i];
        status = 2;
      }else return i;
    }else if(status == 1){
      if(v[i+1]-v[i] == prog) continue;
      else if(v[i+1] < v[i]){
        start = v[i];
        status = 2;
      }else return i;
    }else if(status == 2){
      if(v[i+1] < v[i]) continue;
      else if(v[i+1] < start){
        height = start;
        status = 3;
      }else{
        status = 0;
        i--;
      }
    }else{
      if(v[i+1] < v[i]){
        start = v[i];
        status = 2;
      }else if(v[i+1] < height) continue;
      else{
        status = 0;
        i--;
      }
    }
  }

  return n-1;
}

int main() {
  fout << solve();
}
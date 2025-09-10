#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;

bool check(int n){
  for(int i = 2; i <= n/2; i++)
    if(n % i == 0) return false;

  return true;
}

int main() {
  fin >> n;

  bool found = false;

  for(int i = 1; i <= n/2; i++){
    if(n % i == 0){
      int temp1, temp2;
      temp1 = i;
      temp2 = n/i;

      if(check(temp1) && check(temp2)){
        fout << temp1 << " " << temp2;
        found = true;
        break;
      }
    }
  }

  if(!found) fout << "-1";
}
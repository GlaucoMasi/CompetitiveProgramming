#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;

  bool flag = 0;
  int lastx, lasty, x, y;
  lastx = 0, lasty = 1e9;
  for(int i = 0; i < n; i++){
    fin >> x >> y;

    if(x > lasty || y < lastx){
      fout << "NO";
      flag = 1;
      break;
    }

    lastx = x, lasty = y;
  }

  if(!flag) fout << "YES";
}
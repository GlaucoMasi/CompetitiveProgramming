#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int a, b; fin >> a >> b;
  set<pair<int, int>> s;

  int t = 0;
  while(a*b != 1){
    if(s.count({a, b})){
      fout << -1;
      return 0;
    }

    s.insert({a, b});
    t++;

    if(a%2 && b%2){
      a = 3*a+1;
      b = 3*b+1;
    }else if(!(a%2) && !(b%2)){
      a /= 2;
      b /= 2;
    }else if(a%2) a += 3;
    else b += 3;
  }

  fout << t;
}
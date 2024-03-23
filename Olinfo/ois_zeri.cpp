#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  string s; fin >> s; s += 'x';
  pair<int, int> tot;

  int temp = 0;
  for(auto c : s){
    if(c == 'x'){
      while(!(temp%2)){
        tot.first++;
        temp /= 2;
      }

      while(!(temp%5)){
        tot.second++;
        temp /= 5;
      }

      temp = 0;
    }else{
      temp *= 10;
      temp += c-'0';
    }
  }

  fout << min(tot.first, tot.second);
}
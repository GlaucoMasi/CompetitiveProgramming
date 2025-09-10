#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;

int main() {
  fin >> n;

  int top = n;
  int low = 1;

  string s; 
  fin >> s;

  for(int i = 0; i < n; i++){
    char c = s[i];

    if(c == '<'){
      fout << low << " ";
      low++;
    }else{
      fout << top << " ";
      top--;
    }
  }
}
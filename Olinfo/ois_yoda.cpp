#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  string s;
  string t = "";

  while(fin >> s) t = s + " " + t;
  
  fout << t;
}
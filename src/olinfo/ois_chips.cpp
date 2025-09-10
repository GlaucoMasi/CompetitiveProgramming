#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int t;
  fin >> t;

  for(int i = 0; i < t; i++){
    int a, c, r, g, b;
    fin >> a >> c >> r >> g >> b;

    pair<int, int> first = {a*((r+1)*(r+1) + g*g + b*b) + c*min(min(r+1, g), b), 1};
    pair<int, int> second = {a*(r*r + (g+1)*(g+1) + b*b) + c*min(min(r, g+1), b), 2};
    pair<int, int> third = {a*(r*r + g*g + (b+1)*(b+1)) + c*min(min(r, g), b+1), 3};

    pair<int, int> def = max(max(first, second), third);

    if(def.second == 1) fout << "RED";
    if(def.second == 2) fout << "GREEN";
    if(def.second == 3) fout << "BLUE";
    fout << endl;
  }
}
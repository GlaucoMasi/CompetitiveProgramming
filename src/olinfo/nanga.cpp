#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;
  vector<int> v(1e5 + 100*n, 0);

  int h = 5000;
  for(int i = 0; i < n; i++){
    int a; fin >> a;
    h += a;
    v[h]++;
  }
  
  fout << max_element(v.begin(), v.end()) - v.begin();
}
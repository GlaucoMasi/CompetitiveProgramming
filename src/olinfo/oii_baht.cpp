#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int p; fin >> p;
  while(p--){
    int n; fin >> n;
    vector<int> v(n); for(auto &i : v) fin >> i;
    sort(v.begin(), v.end());

    int ok = 0;
    bool print = 0;
    for(auto i : v){
      if(i > ok+1){
        print = 1;
        fout << ok+1 << '\n';
        break;
      }
      ok += i;
    }

    if(!print) fout << ok+1 << '\n';
  }
}
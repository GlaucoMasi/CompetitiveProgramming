#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, m; fin >> n >> m;
  vector<int> c(n); for(auto &i : c) fin >> i;
  vector<int> next(n); iota(next.begin(), next.end(), 1);
  vector<int> lvl(n, 0);

  while(m--){
    char ch; fin >> ch;

    if(ch == 'M'){
      int a; fin >> a;
      fout << lvl[a] << '\n';
    }else{
      int a, b; fin >> b >> a;
      vector<int> rollback;

      while(a < n){
        int t = min(b, c[a]-lvl[a]);
        lvl[a] += t; b -= t;
        rollback.push_back(a);
        if(b > 0) a = next[a];
        else break;
      }

      for(auto i : rollback) if(i != n && i != a) next[i] = a;
    }
  }
}
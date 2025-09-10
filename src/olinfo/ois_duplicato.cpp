#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  set<int> s;
  int n; fin >> n;
  
  for(int i = 0; i < 2*n-1; i++){
    int a; fin >> a;
    if(s.count(a)) s.erase(s.find(a));
    else s.insert(a);
  }

  fout << *s.begin();
}
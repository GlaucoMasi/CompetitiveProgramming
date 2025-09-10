#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;

  vector<int> best(n+1, 0), padre(n+1);
  long long tot = 0, remove = 0;

  for(int i = 0; i < n; i++){
    long long a; fin >> a;
    padre[i] = a;
  }

  for(int i = 0; i < n; i++){
    long long a; fin >> a;
    tot += a;

    if(a > best[padre[i]]){
      remove += a;
      remove -= best[padre[i]];
      best[padre[i]] = a;
    }
  }

  fout << tot - remove;
}
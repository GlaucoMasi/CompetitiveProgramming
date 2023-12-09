#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
#define ll long long

int main() {
  ll t; ll ans = 0;

  while(fin >> t){
    vector<ll> v(21); v[0] = t;
    for(int i = 1; i < 21; i++) fin >> v[i];

    long long t = 0;
    int par = 1;
    while(1){
      if(par == 1) t += v[0];
      else t -= v[0];

      par = (par+1)%2; 

      if(v.size() == 1) break;

      vector<ll> t; bool ok = 1;
      for(int i = 0; i < v.size()-1; i++){
        t.push_back(v[i+1]-v[i]);
        if(t.back() != 0) ok = 0;
      }

      if(ok) break;
      else v = t;
    }

    ans += t;
  }

  fout << ans;
}
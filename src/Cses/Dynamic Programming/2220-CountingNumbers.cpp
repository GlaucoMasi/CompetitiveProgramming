#include <bits/stdc++.h>
using namespace std;

long long a, b;
vector<long long> calc;

long long ans(long long a){
  if(a < 10) return a+1;

  vector<int> cifre;
  while(a > 0){
    cifre.push_back(a%10);
    a /= 10;
  }
  reverse(cifre.begin(), cifre.end());

  long long tot = 1;
  for(int i = 1; i < cifre.size(); i++) tot += calc[i];
  
  tot += (cifre[0]-1)*calc[cifre.size()-1];

  int last = cifre[0];
  for(int i = 1; i < cifre.size(); i++){
    int unity = cifre[i];
    int power = cifre.size()-i-1;

    tot += unity*calc[power];

    if(power == 0){
      tot++;
      if(unity == last) tot--;
    }
  
    if(unity > last) tot -= calc[power];

    if(unity == last) break;
    last = unity;
  }

  return tot;
}

int main() {
  cin >> a >> b;
  
  calc.resize(20);
  long long k = 1;
  for(int i = 0; i < calc.size(); i++){
    calc[i] = k;
    k *= 9;
  }

  cout << ans(b) - ans(a-1);
}
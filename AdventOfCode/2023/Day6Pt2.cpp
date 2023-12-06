#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

long long conv(string t){
  long long ans = 0;
  for(auto c : t) ans = 10*ans+(c-'0');
  return ans;
}

int main() {
  long long t = 0, d = 0;
  
  string b = "";
  string a; fin >> a;
  while(fin >> a){
    if(a == "Distance:") break;
    b += a;
  }

  t = conv(b);
  b = "";

  while(fin >> a) b += a;
  d = conv(b);

  long double delta = t*t - d*4;
  delta = sqrt(delta);
  long double l = (t-delta)/2, r = (t+delta)/2;

  if(l != (long long)l) l = ceil(l);
  else l++;

  if(r != (long long)r) r = floor(r);
  else r--;

  long long tot = r-l+1;

  fout << tot;
}
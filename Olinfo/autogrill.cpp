#include <bits/stdc++.h>
using namespace std;

set<long long> s;

void inizia() { return; }

void apri(long long p){ s.insert(p); }

void chiudi(long long p){ s.erase(s.find(p)); }

long long chiedi(long long p){
  if(s.empty()) return -1;

  auto temp = s.lower_bound(p);
  if(temp == s.begin()) return *temp;
  if(temp == s.end()) return *prev(temp);

  long long ans1 = *prev(temp);
  long long ans2 = *temp;

  if(ans2-p <= p-ans1) return ans2;
  else return ans1;
}
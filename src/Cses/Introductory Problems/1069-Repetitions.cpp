#include <bits/stdc++.h>
using namespace std;

int main() {
  string s; cin >> s;
  int best = 0, curr = 0;
  char last = 'B';
  for(auto c : s){
    if(c == last) curr++;
    else curr = 1;

    last = c;
    best = max(best, curr);
  }

  cout << best;
}
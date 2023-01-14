#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  string s; cin >> s;

  int pos = 0;
  for(auto i : s){
    if(i == 'R') pos++;
    else pos--;
  }

  cout << abs(pos);
}
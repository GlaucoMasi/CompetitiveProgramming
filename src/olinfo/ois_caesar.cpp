#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, l; cin >> n >> l;
  string a;

  int best = 0;
  map<string, int> m;
  while(n--){
    cin >> a;

    for(int i = 1; i < a.size(); i++){
      a[i] -= (a[0]-'a');
      if(a[i] < 'a') a[i] = 'z'-'a'+a[i]+1;
    }

    a[0] = 'a';
    m[a]++;
    best = max(best, m[a]);
  }

  cout << best;
}
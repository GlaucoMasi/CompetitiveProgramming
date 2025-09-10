#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  pair<int, string> fast = {1e9, ""};

  int sum1 = 0, sum2 = 0;

  int a;
  for(int i = 0; i < n; i++){
    cin >> a;
    fast = min(fast, {a, "Hamilton"});
    sum1 += a;
  }

  for(int i = 0; i < n; i++){
    cin >> a;
    fast = min(fast, {a, "Verstappen"});
    sum2 += a;
  }

  if(sum1 < sum2) cout << "Hamilton";
  else cout << "Verstappen";
  cout << endl << fast.second;
}
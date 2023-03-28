#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, s;
  cin >> n >> s;

  int dav, best = 0;
  for(int i = 0; i < n; i++){
    int a, b, c;
    cin >> a >> b >> c;

    if(i == 0) dav = a+b+c;
    else best = max(best, a+b+c+100*s);
  }

  cout << max(best-dav+1, 0);
}
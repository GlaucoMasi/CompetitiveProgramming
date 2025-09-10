#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int q; cin >> q;
  while(q--){
    long long a, b; cin >> a >> b;
    if(a > b) swap(a, b);


    if(2*a < b || (2*a-b)%3) cout << "NO\n";
    else cout << "YES\n";
  }
}
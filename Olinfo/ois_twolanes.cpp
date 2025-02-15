#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
ifstream fin("input.txt");
ofstream fout("output.txt");
//fout << "Case #" << t << ": ";

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int n; cin >> n;
  string a, b; cin >> a >> b;

  int i = 0;
  while(i < n && (a[i] != 'R' || b[i] != 'R')) i++;
  cout << i;
}
#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
ifstream fin("input.txt");
ofstream fout("output.txt");
//fout << "Case #" << t << ": ";

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int a[3], b[3];
  for(int i = 0; i < 3; i++) cin >> a[i];
  for(int i = 0; i < 3; i++) cin >> b[i];
  cout << abs(a[0]-b[0])+abs(a[1]-b[1])+abs(a[2]-b[2]);
}
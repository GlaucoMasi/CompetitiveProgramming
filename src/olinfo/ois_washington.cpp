#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int t; cin >> t;

  int c1, c2;
  char b1, b2;
  string a1, a2;
  while(t--){
    cin >> a1 >> b1 >> c1 >> a2 >> b2 >> c2;
    
    if(a1[0] == 'S' && c1) c1 = 26-c1;
    if(a2[0] == 'S' && c2) c2 = 26-c2;

    if(a1 == a2) cout << abs(b1-b2)+abs(c1-c2) << '\n';
    else if(a1[0] == a2[0]) cout << b1-'A'+b2-'A'+abs(c1-c2) << '\n';
    else if(a1[1] == a2[1]) cout << abs(b1-b2)+c1+c2 << '\n';
    else cout << b1-'A'+b2-'A'+c1+c2 << '\n';
  }
}
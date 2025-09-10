#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
ifstream fin("input.txt");
ofstream fout("output.txt");
//fout << "Case #" << t << ": ";

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  string a, b; cin >> a >> b;

  if(b == a+'a') cout << -1;
  else{
    int i = -1;
    while(i+1 < a.size() && i+1 < b.size() && a[i+1] == b[i+1]) i++;  
    for(int j = 0; j <= i; j++) cout << a[j]; i++;
    while(i < a.size() && ((i == b.size()-1 && b[i] == a[i]+1) || a[i] == 'z')) cout << a[i++]; 
    cout << (i < a.size() ? (char)(a[i]+1) : 'a');
  }
}
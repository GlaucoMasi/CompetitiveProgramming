#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> v(n);
  int start;

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    
    if(a == -1) start = i;
    else v[a-1] = i;
  }

  cout << start+1 << " ";
  for(int i = 1; i < n; i++){
    start = v[start];
    cout << start+1 << " ";
  }
}
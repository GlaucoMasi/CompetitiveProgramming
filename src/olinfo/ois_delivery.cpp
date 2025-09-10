#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;

  int a, tot = -1, arrive = 1e9;
  for(int i = 0; i < n; i++){
    cin >> a;
    
    if(arrive > a+i){
      tot++;
      arrive = a+i;
    }
  }
  
  cout << arrive << " " << tot;
}
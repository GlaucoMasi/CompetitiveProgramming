#include <bits/stdc++.h>
using namespace std;

int main() {
  string a; cin >> a;
  int n = a.size(); a += a;

  int i = 0, j, k, res;
  while(i < n){
    k = i, j = i+1;
    res = i;

    while(j < a.size() && a[k] <= a[j]){
      if(a[k] == a[j]) k++;
      else k = i;

      j++;
    }

    while(i <= k) i += j-k; 
  }

  cout << a.substr(res, n);
}
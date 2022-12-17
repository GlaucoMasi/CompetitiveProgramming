#include <bits/stdc++.h>
using namespace std;

int n;
vector<bool> v;

void f(int i){
  if(i == -1){
    for(auto i : v) cout << i;
    cout << endl;
    return;
  }

  f(i-1);
  v[i] = 1;
  f(i-1);
  v[i] = 0;
}

int main() {
  cin >> n;
  v.resize(n, 0);
  f(n-1);
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<int> v = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000, 2000, 5000, 10000, 20000, 50000};

  long long sum = 0;
  for(int i = 0; i < v.size(); i++){
    int a; cin >> a;
    sum += (long long)v[i]*a;
  }

  vector<int> ans(v.size());
  for(int i = v.size()-1; i >= 0; i--){
    ans[i] = sum/v[i];
    sum %= v[i];
  }

  for(auto i : ans) cout << i << " ";
}
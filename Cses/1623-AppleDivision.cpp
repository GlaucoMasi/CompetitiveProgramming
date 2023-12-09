#include <bits/stdc++.h>
using namespace std;

int n; long long sum = 0;
vector<long long> v;

long long f(int i, long long t){
  if(i == n) return abs(sum-2*t);

  return min(f(i+1, t+v[i]), f(i+1, t));
}

int main() {
  cin >> n; v.resize(n);
  for(auto &i : v) cin >> i;
  for(auto i : v) sum += i;

  cout << f(0, 0);
}
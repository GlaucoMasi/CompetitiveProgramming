#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; cin >> n;
  vector<int> v(n);

  long long t = 0;
  for(auto &i : v) cin >> i, t += i;

  if(n == 1){
    cout << 0;
    return 0;
  }

  nth_element(v.begin(), v.begin()+n/2, v.end());
  nth_element(v.begin(), v.begin()+n/2-1, v.end());

  t /= n;
  long long a = 0, b = 0;
  for(auto i : v) a += abs(v[n/2]-i), b += abs(v[n/2-1]+1-i);
  cout << min(a, b);
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  vector<long long> v(3);
  for(auto &i : v) cin >> i;

  cout << "First" << endl;

  while(1){
    long long temp = *max_element(v.begin(), v.end());
    cout << 2*temp - (v[0]+v[1]+v[2]-temp) << endl;

    int x; cin >> x;
    v[x-1] += 2*temp - (v[0]+v[1]+v[2]-temp);

    vector<long long> t = v; sort(t.begin(), t.end());
    if(t[1]-t[0] == t[2]-t[1]){
      cout << t[1]-t[0] << endl;
      cin >> x; exit(0);
    }
  }
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, x;
  cin >> n >> x;

  map<int, pair<int, int>> m;
  vector<int> v(n);
  for(int i = 0; i < n; i++){
    cin >> v[i];

    if(m.count(v[i])) m[v[i]].second = i;
    else m[v[i]].first = i;
  }

  sort(v.begin(), v.end());
  for(int i = 0; i < n-1; i++){
    int index = lower_bound(v.begin()+i+1, v.end(), x-v[i]) - v.begin();

    if(index != n && v[index] == x-v[i]){
      if(v[i] != v[index]){
        cout << m[v[i]].first+1 << " " << m[v[index]].first+1;
      }else{
        cout << m[v[i]].first+1 << " " << m[v[index]].second+1;
      }

      exit(0);
    }
  }

  cout << "IMPOSSIBLE";
}
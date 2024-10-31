#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; int x; cin >> n >> x;
  vector<pair<int, int>> v(n);
  for(int i = 0; i < n; i++) cin >> v[i].first, v[i].second = i;
  sort(v.begin(), v.end());
  for(int i = 0; i < n; i++){
    int goal = x-v[i].first;

    int l = 0, r = n-1;
    while(l < r){
      if(l == i || v[l].first+v[r].first < goal) l++;
      else if(r == i || v[l].first+v[r].first > goal) r--;
      else{
        cout << v[i].second+1 << " " << v[l].second+1 << " " << v[r].second+1;
        return 0;
      }
    }
  }

  cout << "IMPOSSIBLE";
}
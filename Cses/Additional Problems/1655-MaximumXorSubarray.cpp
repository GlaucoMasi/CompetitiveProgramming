#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int idx = 1;
vector<pair<int, int>> v(1, {-1, -1});

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;

  int x = 0, best = 0, curr = 0;
  for(int j = 30; j >= 0; j--){
    v[curr].first = idx++;
    v.push_back({-1, -1});
    curr = v[curr].first;
  }

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    x ^= a;

    curr = 0;
    int ans = 0;
    for(int j = 30; j >= 0 && curr != -1; j--){
      if(x&(1<<j)){
        if(v[curr].first != -1){
          curr = v[curr].first;
          ans += (1<<j);
        }else curr = v[curr].second;
      }else{
        if(v[curr].second != -1){
          curr = v[curr].second;
          ans += (1<<j);
        }else curr = v[curr].first;
      }
    }

    best = max(best, ans);

    curr = 0;
    for(int j = 30; j >= 0; j--){
      if(x&(1<<j)){
        if(v[curr].second == -1) v[curr].second = idx++, v.push_back({-1, -1});
        curr = v[curr].second;
      }else{
        if(v[curr].first == -1) v[curr].first = idx++, v.push_back({-1, -1});
        curr = v[curr].first;
      }
    }
  }

  cout << best;
}
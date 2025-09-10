#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, k; cin >> n >> k;
  vector<int> v(n); for(auto &i : v) cin >> i;

  long long ans = 0;
  map<int, int> freq;
  int r = -1, dist = 0;
  for(int i = 0; i < n; i++){
    while(r < n && dist <= k){
      r++;
      freq[v[r]]++;
      dist += (freq[v[r]] == 1);
    }

    ans += r-i;
    freq[v[i]]--;
    dist -= !freq[v[i]];
  }

  cout << ans;
}
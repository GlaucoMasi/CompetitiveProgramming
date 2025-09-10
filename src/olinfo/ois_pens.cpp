#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> freq(n);
  for(auto &i : freq) cin >> i;

  int ans = n;
  for(int i = 0; i < n; i++){
    int disp = freq[i];

    if(freq[i]){
      ans--;
      freq[i] = 1;
      disp--;
    }else freq[i] = 0;

    if(disp && i && !freq[i-1]){
      ans--;
      disp--;
    }

    if(disp && i < n-1 && !freq[i+1]){
      freq[i+1]++;
    }
  }

  cout << ans;
}
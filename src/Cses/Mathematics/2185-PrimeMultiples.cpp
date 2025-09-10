#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  long long n; int k;
  cin >> n >> k;
  vector<long long> v(k); for(auto &i : v) cin >> i;

  long long ans = 0;
  for(int i = 1; i < (1<<k); i++){
    long long temp = 1, cnt = 0;
    for(int j = 0; j < k; j++) if(i&(1<<j)){
      if(temp > n/v[j]){
        temp = n+1;
        break;
      }

      temp *= v[j];
      cnt++;
    }

    ans += n/temp*(cnt%2 ? 1 : -1);
  }

  cout << ans;
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int t; cin >> t;
  while(t--){
    long long a, b, k;
    cin >> a >> b >> k;
    long long sum = a+b+k;
    int s = sqrt(sum), ans = 0;

    auto test = [&](int i){
      long long miss1 = (i-(a%i))%i, miss2 = (i-(b%i))%i;
      if(miss1+miss2 <= k && !((k-miss1-miss2)%i)) ans = max(ans, i);
    };

    for(int i = 1; i <= s; i++) if(!(sum%i)) test(i), test(sum/i);
    cout << ans << '\n';
  }
}
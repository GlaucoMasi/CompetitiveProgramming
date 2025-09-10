#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int mod = 1e9+7;
long long exp(long long a, long long b){
  if(b == 0) return 1;
  if(b == 1) return a;

  long long ans = exp(a, b/2);
  ans = (ans*ans)%mod;
  if(b%2) ans = (ans*a)%mod;
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  bool square = 1;
  long long num = 1, sum = 1, act = 1, prod = 1, num2 = 1;
  for(int i = 0; i < n; i++){
    long long x, k; cin >> x >> k;

    num = (num*(k+1))%mod;
    sum = (sum*(((exp(x, k+1)-1)*exp(x-1, mod-2))%mod))%mod;

    prod = exp(prod, k+1)%mod;
    prod = (prod * exp(exp(x, (k*(k+1)/2)), num2))%mod;
    num2 = (num2*(k+1))%(mod-1);
  }

  cout << num << " " << sum << " " << prod;
}
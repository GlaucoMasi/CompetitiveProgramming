#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int mod = 1e9+7;
  int n; long long k;
  fin >> n >> k;

  int ans = 0;
  unordered_map<long long, int> m;
  for(int i = 0; i < n; i++){
    long long a; fin >> a;
    if(!(k%a) && m.count(k/a)) ans = (ans+m[k/a])%mod;
    m[a]++;
  }

  fout << ans;
}
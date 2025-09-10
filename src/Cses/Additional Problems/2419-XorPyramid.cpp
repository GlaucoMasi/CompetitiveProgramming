#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> fact(2e5+1);

bool bin(int a, int b){
  return fact[b] == (fact[a]+fact[b-a]);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  fact[0] = 0;
  for(int i = 1; i <= 2e5; i++){
    while(!(i%(1<<(fact[i]+1)))) fact[i]++;
    fact[i] += fact[i-1];
  }

  int n; cin >> n;
  vector<int> v(n);
  for(auto &i : v) cin >> i;

  int ans = 0;
  for(int i = 0; i < n; i++) if(bin(i, n-1)) ans ^= v[i];
  cout << ans;
}
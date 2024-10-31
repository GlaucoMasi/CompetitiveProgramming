#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int> v;

vector<long long> f(int l, int r){
  vector<long long> ans;
  int lenght = r-l+1;

  for(int i = 0; i < (1<<lenght); i++){
    long long t = 0;
    for(int j = l; j <= r; j++) if(i&(1<<(j-l))) t += v[j];
    ans.push_back(t);
  }

  return ans;
}

int main() {
  cin >> n >> x;
  v.resize(n); for(auto &i : v) cin >> i;

  long long tot = 0;
  vector<long long> left = f(0, n/2-1), right = f(n/2, n-1);
  sort(right.begin(), right.end());
  for(auto i : left){
    int start = lower_bound(right.begin(), right.end(), x-i)-right.begin();
    int end = upper_bound(right.begin(), right.end(), x-i)-right.begin();
    tot += end-start;
  }

  cout << tot;
}
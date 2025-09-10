#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;
  vector<int> v(n); for(auto &i : v) fin >> i;

  sort(v.begin(), v.end());

  long long ans = 0;
  for(int i = 0; i < n; i++){
    int k = i+1;

    for(int j = i+1; j < n; j++){
      while(k < n && v[i]+v[j] >= v[k]) k++;
      ans += n-k;
    }
  }

  fout << ans;
}
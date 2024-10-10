#include <bits/stdc++.h>
using namespace std;
ifstream fin ("input.txt");
ofstream fout ("output.txt");

int main() {
  int n, q;
  cin >> n >> q;

  vector<long long> v(n+5), sum(n+5);
  
  cin >> v[0];
  sum[2] = v[0];
  for(int i = 1; i < n; i++){
    cin >> v[i];
    sum[i+2] = sum[i+1] + v[i];
  }

  while(q--){
    int a, b;
    cin >> a >> b;
    b++;

    cout << sum[b] - sum[a] << endl;
  }
}
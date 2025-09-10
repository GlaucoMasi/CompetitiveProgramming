#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; long long k; cin >> n >> k;
  int l = log2(k)+2;
  
  vector<vector<int>> fat(n, vector<int>(l, -1));
  for(int i = 0; i < n; i++){
    cin >> fat[i][0];
    fat[i][0]--;
  }

  for(int j = 1; j < l; j++) for(int i = 0; i < n; i++) if(fat[i][j-1] != -1) fat[i][j] = fat[fat[i][j-1]][j-1];

  int curr = 0;
  for(long long i = 0; i < l; i++) if(k & ((long long)1<<i)) curr = fat[curr][i];
  cout << curr+1;
}
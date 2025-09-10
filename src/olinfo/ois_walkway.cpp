#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int INF = 10e8;

int main() {
  fin.tie(0);
  fin.sync_with_stdio(0);

  int n, k;
  fin >> n >> k;
  
  vector<int> v(n);

  for(int i = 0; i < n; i++){
    fin >> v[i];
  }

  sort(v.begin(), v.end(), greater<int>());

  int diff = INF;

  for(int i = 0; i < n-k+1; i++){
    int first = v[i];
    int second = v[i + k - 1];
  
    diff = min(diff, first - second);
  }
  
  fout << diff;
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, k;
  fin >> n >> k;

  float a, b;
  vector<pair<float, int>> v;
  for(int i = 0; i < n; i++){
    fin >> a >> b;
    v.push_back({a-(b*3/2), i+1});
  }

  sort(v.begin(), v.end(), greater<pair<float, int>>());
  for(int i = 0; i < k; i++) fout << v[i].second << endl;
}
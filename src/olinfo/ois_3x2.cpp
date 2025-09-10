#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n;
  fin >> n;

  vector<int> v(n);
  for(int i = 0; i < n; i++) fin >> v[i];
  sort(v.begin(), v.end(), greater<int>());

  int num = n / 3;

  int tot = 0;

  if(num != 0) for(int i = 1; i <= num; i++){
    tot += v[i * 3 - 3];
    tot += v[i * 3 - 2];
  }

  int res = n - num*3;

  if(res != 0) for(int i = num * 3; i < n; i++) tot += v[i];


  fout << tot;
}
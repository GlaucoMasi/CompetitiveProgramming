#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int INF = 1e8;

int n;
vector<int> v, tot, ans;

int main() {
  fin >> n;

  v.resize(n);
  tot.resize(n);
  ans.resize(n);

  for(int i = 0; i < n; i++){
    int a; fin >> a;
    if(a == 0) v[i] = 100;
    if(a == 1) v[i] = 300;
    if(a == 2) v[i] = 500;
  } 

  ans[0] = tot[0] = v[0];
  ans[1] = tot[1] = tot[0] + v[1];
  ans[2] = tot[2] = tot[1] + v[2];

  for(int i = 3; i < n; i++){
    tot[i] = tot[i-1] + v[i];
    
    int temp = INF;
    for(int j = i - 3; j < i; j++) if(ans[j] < temp) temp = ans[j];

    ans[i] = tot[i] - temp;
  }
  
  fout << ans[n-1];
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  char trash;
  vector<int> v(4);
  long long ans = 1, t = pow(256, 3);

  for(int i = 0; i < 4; i++){
    fin >> v[i];
    if(i != 3) fin >> trash;
  }

  for(int i = 0; i < 4; i++){
    int a; fin >> a;
    if(i != 3) fin >> trash;
    ans += (long long)(a-v[i])*t;
    t /= 256;
  }

  fout << ans;
}
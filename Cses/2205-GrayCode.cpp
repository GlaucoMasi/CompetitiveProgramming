#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> v(1<<n);
  for(int j = 0; j < n; j++){
    int i = 0, l = 1<<j;
    bool sw = 1, ass = 0;
    while(i < v.size()){
      for(int k = 0; k < l; k++, i++) v[i] += (1<<j)*ass;
      if(!sw) sw = 1;
      else{
        sw = 0;
        ass = !ass;
      }
    }
  }

  for(auto i : v){
    for(int j = n-1; j >= 0; j--) cout << ((i&(1<<j)) != 0);
    cout << '\n';
  }
}
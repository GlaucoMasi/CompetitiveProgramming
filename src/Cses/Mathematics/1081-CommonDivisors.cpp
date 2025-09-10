#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> pres(1e6+1);
  while(n--){
    int a; cin >> a;
    pres[a]++;
  }

  for(int i = 1e6; i >= 1; i--){
    int tot = 0;
    for(int j = i; j <= 1e6; j += i){
      tot += pres[j];
      if(tot >= 2){
        cout << i;
        return 0;
      }
    }
  }
}
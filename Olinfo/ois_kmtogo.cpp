#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
ifstream fin("input.txt");
ofstream fout("output.txt");
//fout << "Case #" << t << ": ";

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int n; cin >> n;
  vector<int> v(10);
  
  for(int i = 1; i <= n; i++){
    int k = i;
    while(k){
      int t = k%10; k /= 10;
      v[t]++;
    }
  }

  for(auto i : v) cout << i << " ";
}
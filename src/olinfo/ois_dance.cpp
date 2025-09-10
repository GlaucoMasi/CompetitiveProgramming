#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
ifstream fin("input.txt");
ofstream fout("output.txt");
//fout << "Case #" << t << ": ";

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int n, d;
  cin >> n >> d;
  vector<int> a(n), b(n);
  for(auto &i : a) cin >> i;
  for(auto &i : b) cin >> i;

  for(int i = 0; i < n; i++){
    if(b[i]-a[i] > d){
      cout << "NO";
      return 0;
    }
  }

  cout << "YES";
}
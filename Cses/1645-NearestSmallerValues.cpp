#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  stack<pair<int, int>> s; s.push({-1e9, 0});

  for(int i = 1; i <= n; i++){
    int a; cin >> a;
    while(s.top().first >= a) s.pop();
    cout << s.top().second << " ";
    s.push({a, i});
  }
}
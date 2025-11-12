#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> g(26);
vector<int> status(26);

bool found = false;
void f(int i) {
  if(status[i] == 1) found = true;
  if(status[i]) return;

  status[i] = 1;
  for(auto j : g[i]) f(j);
  status[i] = 2;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;
  for(int i = 0; i < n; i++) {
    char a, dir, b;
    cin >> a >> dir >> b;
    if(dir == '>') g[a-'a'].push_back(b-'a');
    else g[b-'a'].push_back(a-'a');
  }

  for(int i = 0; i < 26; i++) if(!status[i]) f(i);

  cout << (found ? ":(" : ":)");
}
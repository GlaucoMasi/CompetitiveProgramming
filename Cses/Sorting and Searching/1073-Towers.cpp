#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; cin >> n;
  vector<int> t;

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    int idx = upper_bound(t.begin(), t.end(), a)-t.begin();

    if(idx == t.size()) t.push_back(a);
    else t[idx] = a;
  }

  cout << t.size();
}
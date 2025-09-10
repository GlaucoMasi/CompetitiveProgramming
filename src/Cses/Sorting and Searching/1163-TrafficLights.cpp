#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int x, n; cin >> x >> n;
  set<int> s; s.insert(0); s.insert(x);
  multiset<int> empty; empty.insert(x);

  while(n--){
    int a; cin >> a; s.insert(a);
    auto t = s.find(a), pr = prev(t), nxt = next(t);

    empty.erase(empty.find(*nxt-*pr));
    empty.insert(a-*pr);
    empty.insert(*nxt-a);

    cout << *empty.rbegin() << " ";
  }
}
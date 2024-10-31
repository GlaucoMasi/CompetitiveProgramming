#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m; cin >> n >> m;
  multiset<int> s;

  while(n--){
    int a; cin >> a;
    s.insert(a);
  }

  while(m--){
    int a; cin >> a;
    
    auto temp = s.upper_bound(a);
    if(s.empty() || temp == s.begin()) cout << -1;
    else{
      temp = prev(temp);
      cout << *temp;
      s.erase(temp);
    }

    cout << '\n';
  }
}
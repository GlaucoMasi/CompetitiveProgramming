#include <bits/stdc++.h>
using namespace std;

int main() {
  int t; cin >> t;

  while(t--){
    int a; cin >> a;
    int l = log2(a);

    vector<int> path; path.push_back(a);

    while(a){
      for(int i = 0; 1; i++){
        if(a & (1<<i)){
          a -= (1<<i);
          path.push_back(a);
          break;
        }
      }
    }

    path.pop_back();
    a = path.back();

    for(int i = l+1; i > 0; i--){
      if(a & (1<<(i))){
        a -= (1<<(i-1));
        path.push_back(a);
      }
    }

    cout << path.size() << " ";
    for(auto i : path) cout << i << " ";
    cout << '\n';
  }
}
#include <bits/stdc++.h>
using namespace std;

int conta(int n, vector<int> &a, vector<int> &p, vector<int> &d){
  vector<vector<int>> v = {a, p, d};
  sort(v.begin(), v.end());
  
  int ans = -1;

  do{
    set<int> s;

    int i = -1;
    for(i; i < n-1; i++){
      if(s.count(v[0][i+1])) break;
      s.insert(v[0][i+1]);
    }

    int j = -1, z = -1;
    auto prop = [&] {
      for(j; j < n-1; j++){
        if(s.count(v[1][j+1])) break;
        s.insert(v[1][j+1]);
      }

      for(z; z < n-1; z++){
        if(s.count(v[2][z+1])) break;
        s.insert(v[2][z+1]);
      }

      ans = max(ans, i+j+z+3);
    };

    prop();

    while(i >= 0){
      s.erase(v[0][i]); i--;
      prop();
    }
  }while(next_permutation(v.begin(), v.end()));

  return ans;
}
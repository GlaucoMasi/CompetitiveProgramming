#include <bits/stdc++.h>
#include <variant>
using namespace std;

variant<bool, vector<int>> find_tour(int n, vector<int> a){
  if(a[0] != 2 || a.back() != 2) return false;
  for(int i = 1; i < n-1; i++) if(a[i] < 2) return false;

  int open = 2;
  queue<int> back;
  vector<int> cat(n), ans;
  ans.push_back(0);
  for(int i = 1; i < n; i++){
    if(open < 0) return false;

    if(a[i] == open+2){
      open += 2;

      back.push(i);
    }else if(a[i] == open){
      open -= 2;

      ans.push_back(i);
      if(i != n-1){
        if(back.empty()) return false;
        ans.push_back(back.front());
        back.pop();
      }
    }else if(a[i] == open+1){
      ans.push_back(i);
    }else return false;
  }

  return ans;
}
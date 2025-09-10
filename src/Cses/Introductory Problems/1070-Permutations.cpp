#include <bits/stdc++.h>
using namespace std;

int n;
bool found = 0;
vector<int> ans;
queue<int> q;

void f(vector<int> &v){
  if(found) return;

  if(v.size() == n){
    found = 1;
    return;
  }

  bool stop = 0;
  int first = q.front();
  while(!stop || q.front() != first){
    int curr = q.front();
    if(curr == first) stop = 1;
    q.pop();

    if(v.size() == 0 || abs(v[v.size()-1] - curr) != 1){
      v.push_back(curr);
      f(v);
      if(found) break;
      
      v.pop_back();
    }

    q.push(curr);
  }
}

int main() {
  cin >> n;

  for(int i = 1; i <= n; i++) q.push(i);

  f(ans);
  if(ans.size() == 0) cout << "NO SOLUTION";
  else for(auto i : ans) cout << i << " ";
}
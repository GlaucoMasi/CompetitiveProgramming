#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
bool done = 0;
vector<int> ans;
multiset<int> s;

int top(){
  return *prev(s.end());
}

bool pres(int i){
  return s.count(i);
}

void add(int i){
  s.insert(i);
}

void rem(int i){
  s.erase(s.find(i));
}

void f(int l, int r, bool side){
  if(l > r) done = 1;
  if(done) return;
  
  int val = (side ? top() : ans[n-1]-top());
  for(int i = 0; i < n; i++){
    if(i < l || i > r){
      if(!pres(abs(val-ans[i]))){
        for(int j = 0; j < i; j++) if(j < l || j > r) add(abs(val-ans[j]));
        return;
      }else rem(abs(val-ans[i]));
    }
  }

  ans[side ? r-- : l++] = val;

  f(l, r, 0);
  f(l, r, 1);

  if(done) return;
  
  if(side) r++;
  else l--;
  for(int i = 0; i < n; i++) if(i < l || i > r) add(abs(val-ans[i]));
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  ans.resize(n);
  for(int i = 0; i < n*(n-1)/2; i++){
    int a; cin >> a;
    add(a);
  }

  ans[0] = 0;
  ans[n-1] = top();
  rem(top());
  f(1, n-2, 0);
  f(1, n-2, 1);

  for(auto i : ans) cout << i << " ";
}
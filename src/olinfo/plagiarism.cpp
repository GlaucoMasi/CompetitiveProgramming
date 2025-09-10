#include <bits/stdc++.h>
using namespace std;

int n, v;
vector<pair<int, int>> a, b;

int l, r;

bool test() {
  int doub;
  int off = b[l].second-a[l].second;

  if(a[l].first == b[l].first) doub = 0;
  else{
    if(2*a[l].first == b[l].first) doub = 1;
    else if(a[l].first == 2*b[l].first) doub = -1;
    else return 0;
  }

  for(int i = l+1; i <= r; i++){
    if(!doub && a[i].first != b[i].first) return 0;
    if(doub == 1 && 2*a[i].first != b[i].first) return 0;
    if(doub == -1 && a[i].first != 2*b[i].first) return 0;

    if(a[i].second + off != b[i].second) return 0;
  }

  cout << "TRANSFORMED " << r-l+1; 
  return 1;
}

int main() {
  cin >> n >> v;

  a.resize(n); b.resize(n);
  for(auto &i : a) cin >> i.first >> i.second;
  for(auto &i : b) cin >> i.first >> i.second;
  
  l = 0, r = n-1;

  while(l < n && a[l] == b[l]) l++;

  if(l == n){
    cout << "SAME";
    return 0;
  }

  while(r >= 0 && a[r] == b[r]) r--;

  if(!test()){
    reverse(a.begin()+l, a.begin()+r+1);
    if(!test()) cout << "ORIGINAL " << r-l+1;
  }
}
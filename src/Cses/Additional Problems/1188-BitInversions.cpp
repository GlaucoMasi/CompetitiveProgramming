#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
 
  string s; cin >> s; s += '.';
 
  priority_queue<int> best;
  vector<int> freq(s.size());
  set<pair<int, int>> interv;
 
  auto add = [&](int l, int r){
    if(r < l) return;
    interv.insert({l, r});
    freq[r-l+1]++;
    if(freq[r-l+1] == 1) best.push(r-l+1);
  };
 
  auto rem = [&](int l, int r){
    if(r < l) return;
    interv.erase(interv.find({l, r}));
    freq[r-l+1]--;
  };
 
  auto get = [&]{
    while(!freq[best.top()]) best.pop();
    return best.top();
  };
 
  int last = 0;
  for(int i = 0; i < s.size(); i++){
    if(s[i] != s[last]){
      add(last, i-1);
      last = i;
    }
  }
  
  int n; cin >> n;
  while(n--){
    int i; cin >> i; i--;
 
    auto t = prev(interv.upper_bound({i, 1e9}));
    auto [l1, r1] = *t;
    
    if(l1 != i){
      if(r1 != i){
        rem(l1, r1);
        add(l1, i-1);
        add(i, i);
        add(i+1, r1);
      }else{
        if(r1 != s.size()-2){
          auto [c, d] = *next(t);
          rem(c, d);
          add(c-1, d);
        }else add(i, i);
 
        rem(l1, r1);
        add(l1, r1-1);
      }
    }else{
      if(r1 == i){
        if(i == 0){
          auto [c, d] = *next(t);
          rem(c, d);
          add(c-1, d);
        }else if(i == s.size()-2){
          auto [c, d] = *prev(t);
          rem(c, d);
          add(c, d+1);
        }else{
          auto [c, d] = *prev(t);
          auto [e, f] = *next(t);
          rem(c, d);
          rem(e, f);
          add(c, f);
        }
 
        rem(i, i);
      }else{
        if(i != 0){
          auto [c, d] = *prev(t);
          rem(c, d);
          add(c, d+1);
        }else add(i, i);
 
        rem(l1, r1);
        add(l1+1, r1);
      }
    }
 
    cout << get() << " ";
  }
}
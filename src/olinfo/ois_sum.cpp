#include <bits/stdc++.h>
using namespace std;

string a, b, tot;
vector<bool> used(10);
map<char, int> match;

void f(int idx, int carry){
  if(idx == a.size()){
    if((!match[a.back()] && a.size() != 1) || (!match[b.back()] && b.size() != 1)) return;
    
    if((!carry && tot.size() == a.size()) || (carry && tot.size() > a.size())){
      for(int i = a.size()-1; i >= 0; i--) cout << match[a[i]]; cout << endl;
      for(int i = b.size()-1; i >= 0; i--) cout << match[b[i]];
      exit(0);
    }else return;
  }

  char c1 = a[idx], c2 = b[idx];
  char ans = tot[idx]; int goal = ans-48-carry;

  if(match[c1] != -1 && match[c2] != -1){
    if(match[c1] + match[c2] == goal) f(idx+1, 0);
    else if(match[c1] + match[c2] == 10 + goal) f(idx+1, 1);
  }else if(match[c1] != -1){
    int next = goal - match[c1];

    if(next >= 0 && !used[next]){
      used[next] = 1;
      match[c2] = next;

      f(idx+1, 0);

      used[next] = 0;
      match[c2] = -1;
    }
    
    if(next+10 < 10 && !used[next+10]){
      used[next+10] = 1;
      match[c2] = next+10;

      f(idx+1, 1);

      used[next+10] = 0;
      match[c2] = -1;
    }
  }else if(match[c2] != -1){
    int next = goal - match[c2];

    if(next >= 0 && !used[next]){
      used[next] = 1;
      match[c1] = next;

      f(idx+1, 0);

      used[next] = 0;
      match[c1] = -1;
    }
    
    if(next+10 < 10 && !used[next+10]){
      used[next+10] = 1;
      match[c1] = next+10;

      f(idx+1, 1);

      used[next+10] = 0;
      match[c1] = -1;
    }
  }else{
    for(int i = 0; i < 10; i++){
      if(used[i]) continue;

      if(goal - i >= 0 && !used[goal-i] && ((c1 == c2 && (i == goal-i)) || ((c1 != c2 && (i != goal-i))))){
        used[i] = 1; used[goal-i] = 1;
        match[c1] = i; match[c2] = goal-i;

        f(idx+1, 0);

        used[i] = 0; used[goal-i] = 0;
        match[c1] = -1; match[c2] = -1;
      }

      if(goal-i+10 < 10 && !used[goal-i+10] && ((c1 == c2 && (i == goal-i+10)) || ((c1 != c2 && (i != goal-i+10))))){
        used[i] = 1; used[goal-i+10] = 1;
        match[c1] = i; match[c2] = goal-i+10;

        f(idx+1, 1);

        used[i] = 0; used[goal-i+10] = 0;
        match[c1] = -1; match[c2] = -1;
      }
    }
  }
}

int main() {
  cin >> a >> b >> tot;
  reverse(a.begin(), a.end());
  reverse(b.begin(), b.end());
  reverse(tot.begin(), tot.end());

  for(int i = 0; i < 10; i++) match['A'+i] = -1;

  f(0, 0);
}
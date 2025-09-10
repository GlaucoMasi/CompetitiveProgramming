#include <bits/stdc++.h>
using namespace std;

struct mos{
  int down = 0, right = 0;
};

int a, b, n;
vector<vector<int>> ans;
vector<mos> v;

map<pair<int, int>, vector<int>> m;
map<int, vector<int>> l, u;

vector<bool> used;

void f(int x, int y){
  if(y == b){
    x++;
    y = 0;
  }

  if(x == b){
    for(auto i : ans){
      for(auto j : i) cout << j << " ";
      cout << endl;
    }

    exit(0);
  }

  // lo prendo per la sinitra e vedo se va bene sopra
  if(x == 0){
    if(!l.count(v[ans[x][y-1]].right)) return;
    for(auto i : l[v[ans[x][y-1]].right]){
      if(used[i]) continue;

      used[i] = 1;
      ans[x][y] = i;
      f(x, y+1);
      used[i] = 0;
    }
  }else if(y == 0){
    if(!u.count(v[ans[x-1][y]].down)) return;
    for(auto i : u[v[ans[x-1][y]].down]){
      if(used[i]) continue;

      used[i] = 1;
      ans[x][y] = i;
      f(x, y+1);
      used[i] = 0;
    }
  }else{
    if(!m.count({v[ans[x][y-1]].right, v[ans[x-1][y]].down})) return;

    for(auto i : m[{v[ans[x][y-1]].right, v[ans[x-1][y]].down}]){
      if(used[i]) continue;

      used[i] = 1;
      ans[x][y] = i;
      f(x, y+1);
      used[i] = 0;
    }
  }
}

int main() {
  cin >> a >> b >> n;
  ans.resize(b, vector<int>(b));
  v.resize(n);
  used.resize(n);

  vector<vector<char>> temp(a, vector<char>(a));
  for(int i = 0; i < n; i++){
    for(int x = 0; x < a; x++){
      for(int y = 0; y < a; y++){
        cin >> temp[x][y];
      }
    }

    int up = 0, left = 0;

    for(int x = 0; x < a; x++){
      if(temp[0][x] == '1') up += pow(2, x);
      if(temp[a-1][x] == '1') v[i].down += pow(2, x);
      if(temp[x][0] == '1') left += pow(2, x);
      if(temp[x][a-1] == '1') v[i].right += pow(2, x);
    }

    if(!m.count({left, up})) m[{left, up}] = {};
    m[{left, up}].push_back(i);

    if(!l.count(left)) l[left] = {};
    l[left].push_back(i);

    if(!u.count(up)) u[up] = {};
    u[up].push_back(i);
  }

  for(int i = n-1; i >= 0; i--){
    ans[0][0] = i;
    f(0, 1);
  }
}
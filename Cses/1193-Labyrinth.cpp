#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a, b;
  pair<int, int> start, end;
  cin >> a >> b;
  vector<vector<int>> father(a, vector<int>(b, -3));
 
  char c;
  for(int i = 0; i < a; i++){
    for(int j = 0; j < b; j++){
      cin >> c;
 
      if(c == 'A') start = {i, j};
      if(c == 'B') end = {i, j};
      if(c == '#') father[i][j] = 3;
    }
  }
  
  queue<pair<pair<int, int>, int>> q;
  q.push({start, 3});
  while(!q.empty()){
    int x = q.front().first.first, y = q.front().first.second;
    auto curr = q.front().second;
    q.pop();

    if(father[x][y] != -3) continue;
    father[x][y] = curr;

    if(x == end.first && y == end.second){
      string ans = "";

      while(x != start.first || y != start.second){
      if(father[x][y] == -1) ans += 'U';
      else if(father[x][y] == 1) ans += 'D';
      else if(father[x][y] == -2) ans += 'L';
      else if(father[x][y] == 2) ans += 'R';
        
      if(father[x][y] % 2 == 0) y -= (father[x][y]/2);
      else x -= father[x][y];
      }

      cout << "YES" << endl << ans.size() << endl;
      for(int i = ans.size()-1; i > -1; i--) cout << ans[i];
      return 0;
    }

    if(x > 0 && father[x-1][y] == -3) q.push({{x-1, y}, -1});
    if(x < a-1 && father[x+1][y] == -3) q.push({{x+1, y}, 1});
    if(y > 0 && father[x][y-1] == -3) q.push({{x, y-1}, -2});
    if(y < b-1 && father[x][y+1] == -3) q.push({{x, y+1}, 2});
  }
    
  cout << "NO";
}
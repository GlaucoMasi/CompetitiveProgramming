#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

string s;
int tot = 0;
bool v[7][7] = {0};

bool free(int x, int y){
  if(x < 0 || y < 0 || x == 7 || y == 7) return 0;
  return !v[x][y];
}

void f(int x, int y, int i){
  if(i == 48){
    tot += (x == 6 && y == 0);
    return;
  }

  if(x == 6 && y == 0) return;
  if(!free(x+1, y) && !free(x-1, y) && free(x, y+1) && free(x, y-1)) return;
  if(!free(x, y+1) && !free(x, y-1) && free(x+1, y) && free(x-1, y)) return;

  v[x][y] = 1;

  if(x && !v[x-1][y] && (s[i] == '?' || s[i] == 'U')) f(x-1, y, i+1);
  if(y && !v[x][y-1] && (s[i] == '?' || s[i] == 'L')) f(x, y-1, i+1);
  if(x < 6 && !v[x+1][y] && (s[i] == '?' || s[i] == 'D')) f(x+1, y, i+1);
  if(y < 6 && !v[x][y+1] && (s[i] == '?' || s[i] == 'R')) f(x, y+1, i+1);

  v[x][y] = 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> s;
  f(0, 0, 0);
  cout << tot;
}
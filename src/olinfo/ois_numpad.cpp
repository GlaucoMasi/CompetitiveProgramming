#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  string n;
  fin >> n;

  int tot = 0;
  int last = 0;
  int x = 2, y = 4;
  for(int i = 0; i < n.size(); i++){
    int curr = n[i] - '0';

    tot++;

    if(curr != last){
      int temp_x = curr % 3;
      if(temp_x == 0) temp_x = 3;
      if(curr == 0) temp_x = 2;

      int temp_y = curr / 3 + 1;
      if(!(curr % 3)) temp_y--;
      if(curr == 0) temp_y = 4;

      tot += abs(x - temp_x);
      tot += abs(y - temp_y);
      last = curr;
      x = temp_x;
      y = temp_y;
    }
  }

  fout << tot;
}
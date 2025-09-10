#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int organizza(int N, int X, int Y, vector<int> A, vector<int> B){
  vector<pair<int, int>> comp;
  for(auto &i : A) comp.push_back({i, 1});
  for(auto &i : B) comp.push_back({i, 2});
  comp.push_back({X, 3});
  comp.push_back({Y, 4});
  sort(comp.begin(), comp.end());

  vector<int> inizio(1, 0), fine(1, 0);
  int index = 0, last = comp[0].first;
  for(auto &i : comp){
    if(i.first != last){
      index++;
      inizio.push_back(0);
      fine.push_back(0);

      if(i.first > last+1){
        index++;
        inizio.push_back(0);
        fine.push_back(0);
      }
    }

    if(i.second == 1) inizio[index]++;
    if(i.second == 2) fine[index]++;
    if(i.second == 3) X = index;
    if(i.second == 4) Y = index;
    
    last = i.first;
  }

  int curr = 0;
  int ans = N;
  for(int i = 0; i <= index; i++){
    curr += inizio[i];

    if(i >= X && i <= Y) ans = min(ans, curr);

    curr -= fine[i];
  }

  return N - ans;
}
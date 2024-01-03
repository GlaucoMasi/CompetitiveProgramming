#include <bits/stdc++.h>
using namespace std;

vector<pair<array<int, 4>, vector<pair<int, char>>>> moves;
vector<pair<int, char>> hand(3), table(4);
vector<pair<int, char>> curr;

void f(int i, int sev, bool bello, int tot, int sum){
  if(i == 4){
    for(int j = 0; j < 3; j++){
      if(sum != hand[j].first) continue;

      array<int, 4> temp = {bello, 0, sev, tot};
      if(hand[j].first == 7 && hand[j].second == 'G') temp[0] |= 1;
      temp[3]++;
      if(hand[j].first == 7) temp[2]++;
      if(temp[3] == 5) temp[1] = 1;
      
      curr.push_back(hand[j]);
      moves.push_back({temp, curr});
      curr.pop_back();
    }
  }else{
    curr.push_back(table[i]);
    f(i+1, sev + (table[i].first == 7), bello | (table[i].first == 7 && table[i].second == 'G'), tot+1, sum+table[i].first);
    curr.pop_back();
    
    f(i+1, sev, bello, tot, sum);
  }
}

int main() {
  for(auto &i : hand) cin >> i.first >> i.second;
  for(auto &i : table) cin >> i.first >> i.second;

  f(0, 0, 0, 0, 0);
  sort(moves.begin(), moves.end(), greater<>());
  for(auto j : moves[0].second) cout << j.first << j.second << " ";
}
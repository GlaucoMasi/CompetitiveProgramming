#include <bits/stdc++.h>
using namespace std;

vector<int> disconnect(vector<int> l);
void series(vector<int> g);

void study(int n){
  vector<vector<int>> groups; groups.push_back(vector<int>(n));
  iota(groups[0].begin(), groups[0].end(), 0);

  int max = 1;
  while(2*max < n) max *= 2;
  for(int i = 0; i < 10; i++){
    vector<int> query;

    for(auto group : groups) for(int j = 0; j < min((int)group.size(), max); j++) query.push_back(group[j]);

    query = disconnect(query);

    vector<vector<int>> next;
    for(auto group : groups){
      vector<int> v1, v2;
      
      for(auto j : group){
        if(!query[j]) v1.push_back(j);
        else v2.push_back(j);
      }

      if(!v1.empty()) next.push_back(v1);
      if(!v2.empty()) next.push_back(v2);
    }

    groups = next; max /= 2;
  }

  for(auto t : groups) series(t);
}
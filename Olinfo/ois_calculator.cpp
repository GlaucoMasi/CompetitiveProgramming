#include <bits/stdc++.h>
using namespace std;

#define maxm 9000
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
vector<pair<int, array<int, 3>>> dist(maxm, {1e9, {-1, -1,-1}});
vector<int> reached;
vector<bool> prop(maxm);

array<string, 10> op = {"+", "-", "*", "/", "%", "<<", ">>", "&", "^", "|"};

void print(int i){
  if(i == 1) cout << 1;
  else{
    cout << '(';
    print(dist[i].second[0]);
    cout << op[dist[i].second[2]];
    print(dist[i].second[1]);
    cout << ')';
  }
}

int main() {
  int m; cin >> m;

  pq.push({0, 1});
  dist[1].first = 0;
  while(!pq.empty()){
    int curr = pq.top().second; pq.pop();

    if(curr == m) break;

    if(prop[curr]) continue;
    prop[curr] = 1;
    reached.push_back(curr);

    for(auto i : reached){
      if(curr+i < maxm && dist[curr+i].first > dist[curr].first+dist[i].first+1){
        dist[curr+i] = {dist[curr].first+dist[i].first+1, {curr, i, 0}};
        pq.push({dist[curr+i].first, curr+i});
      }

      if(curr-i >= 0 && dist[curr-i].first > dist[curr].first+dist[i].first+1){
        dist[curr-i] = {dist[curr].first+dist[i].first+1, {curr, i, 1}};
        pq.push({dist[curr-i].first, curr-i});
      }

      if(curr*i >= 0 && curr*i < maxm && dist[curr*i].first > dist[curr].first+dist[i].first+1){
        dist[curr*i] = {dist[curr].first+dist[i].first+1, {curr, i, 2}};
        pq.push({dist[curr*i].first, curr*i});
      }

      if(i && dist[curr/i].first > dist[curr].first+dist[i].first+1){
        dist[curr/i] = {dist[curr].first+dist[i].first+1, {curr, i, 3}};
        pq.push({dist[curr/i].first, curr/i});
      }

      if(i && dist[curr%i].first > dist[curr].first+dist[i].first+1){
        dist[curr%i] = {dist[curr].first+dist[i].first+1, {curr, i, 4}};
        pq.push({dist[curr%i].first, curr%i});
      }

      if((curr<<i) >= 0 && (curr<<i) < maxm && dist[curr<<i].first > dist[curr].first+dist[i].first+1){
        dist[curr<<i] = {dist[curr].first+dist[i].first+1, {curr, i, 5}};
        pq.push({dist[curr<<i].first, curr<<i});
      }

      if(dist[curr>>i].first > dist[curr].first+dist[i].first+1){
        dist[curr>>i] = {dist[curr].first+dist[i].first+1, {curr, i, 6}};
        pq.push({dist[curr>>i].first, curr>>i});
      }

      if((curr&i) < maxm && dist[curr&i].first > dist[curr].first+dist[i].first+1){
        dist[curr&i] = {dist[curr].first+dist[i].first+1, {curr, i, 7}};
        pq.push({dist[curr&i].first, curr&i});
      }

      if((curr^i) < maxm && dist[curr^i].first > dist[curr].first+dist[i].first+1){
        dist[curr^i] = {dist[curr].first+dist[i].first+1, {curr, i, 8}};
        pq.push({dist[curr^i].first, curr^i});
      }
      
      if((curr|i) < maxm && dist[curr|i].first > dist[curr].first+dist[i].first+1){
        dist[curr|i] = {dist[curr].first+dist[i].first+1, {curr, i, 9}};
        pq.push({dist[curr|i].first, curr|i});
      }
    }
  }

  print(m);
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int INF = 10e7;

int main() {
  fin.tie(0);
  fin.sync_with_stdio(0);

  int n;
  fin >> n;
  
  priority_queue<int, vector<int>, greater<int>> pq;
  int cost = 0;

  for(auto i = 0; i < n; i++){
    int a;
    fin >> a;
    pq.push(a);
  }

  while(!pq.empty()){
    int first = pq.top();
    pq.pop();
    
    if(pq.empty()) break;

    int second = pq.top();
    pq.pop();

    pq.push(first + second);
    cost += first + second;
  }

  fout << cost;
}
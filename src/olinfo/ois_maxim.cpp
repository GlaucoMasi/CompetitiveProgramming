#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, k; cin >> n >> k;

  int saddest = 0;
  deque<pair<int, int>> minqueue, maxqueue;
  for(int i = 0; i < n; i++){
    int a; cin >> a;

    while(!maxqueue.empty() && maxqueue.front().first < i-k) maxqueue.pop_front();
    while(!maxqueue.empty() && maxqueue.back().second <= a) maxqueue.pop_back();
    if(!maxqueue.empty()) saddest = max(saddest, maxqueue.front().second-a);
    maxqueue.push_back({i, a});

    while(!minqueue.empty() && minqueue.front().first < i-k) minqueue.pop_front();
    while(!minqueue.empty() && minqueue.back().second >= a) minqueue.pop_back();
    if(!minqueue.empty()) saddest = max(saddest, a-minqueue.front().second);
    minqueue.push_back({i, a});
  }

  cout << saddest;
}
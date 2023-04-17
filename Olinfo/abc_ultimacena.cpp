#include <bits/stdc++.h>
using namespace std;

bool found = 0;
int n, m;
vector<pair<int, int>> edges;
set<int> taken;

bool f(int i) {
  if(taken.size() > 10) return 0;

  if(i == m) return 1;

  if(taken.count(edges[i].first) || taken.count(edges[i].second)) return f(i+1);
  else{
    taken.insert(edges[i].first);
    if(f(i+1)) return 1;

    taken.erase(taken.find(edges[i].first));
    taken.insert(edges[i].second);
    
    if(f(i+1)) return 1;

    taken.erase(taken.find(edges[i].second));
    return 0;
  }
}

int riassumi(int N, int M, int A[], int B[], int S[]){
  n = N; m = M;
  for(int i = 0; i < m; i++) edges.push_back({A[i], B[i]});

  f(0);

  int i = 0;
  for(i; 1; i++){
    S[i] = *taken.begin();
    taken.erase(taken.begin());
    if(taken.empty()) break;
  }

  return i+1;
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int best_score(int N, int K, vector<int> &monete){
  vector<int> ans(N);

  int tot = 0, curr = 0;
  deque<int> dq;
  for(int i = 0; i < N; i++){
    tot += monete[i];
    
    if(i < K) ans[i] = tot;
    else{
      while(!dq.empty() && dq.front() < i-K) dq.pop_front();

      ans[i] = tot - ans[dq.front()];
    }

    while(!dq.empty() && ans[dq.back()] >= ans[i]) dq.pop_back();
    dq.push_back(i);
  }

  return ans[N-1];
}
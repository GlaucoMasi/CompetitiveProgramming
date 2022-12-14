#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, l; fin >> n >> l;

  int ans = 2e9, a;
  priority_queue<pair<int, int>> pq;
  for(int i = 0; i < n; i++){
    fin >> a; pq.push({a, i});

    if(i >= l-1){
      while(pq.top().second <= i-l) pq.pop();
      auto temp = pq.top(); pq.pop();

      while(pq.top().second <= i-l) pq.pop();
      ans = min(ans, (temp.first-pq.top().first)/2);

      pq.push(temp);
    }
  }

  fout << ans;
}
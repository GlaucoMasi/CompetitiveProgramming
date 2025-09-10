#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, r; 
  long long tot = 0;
  fin >> n >> r;
  r--;
  vector<bool> v(n, 0);
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

  for(int i = 0; i < n; i++){
    int a, b; fin >> a >> b; a--; b--;

    if(!v[b]){
      v[b] = 1;
      tot += abs(r - a);
    }else pq.push({b, a});
  }

  for(int i = 0; i < n; i++){
    if(v[i]) continue;

    auto curr = pq.top(); pq.pop();
    v[i] = 1;
    tot += (abs(r - curr.second) + abs(i - curr.first));
  }

  fout << tot;
}
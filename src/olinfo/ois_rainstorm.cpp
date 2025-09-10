#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int comps;
vector<int> father, sz;

int get(int a){
  if(father[a] == a) return a;
  else return father[a] = get(father[a]);
}

int main() {
  int n, m; fin >> n >> m;

  comps = n;
  father.resize(n);
  iota(father.begin(), father.end(), 0);
  sz.resize(n, 1);
  priority_queue<pair<int, pair<int, int>>> pq;

  int a, b, c;  
  while(m--){
    fin >> a >> b >> c;
    pq.push({c, {a, b}});
  }

  int ans = 1e9;

  while(comps > 1){
    auto curr = pq.top(); pq.pop();

    int a = get(curr.second.first), b = get(curr.second.second);

    if(a != b){
      ans = min(ans, curr.first);
      
      if(sz[a] < sz[b]) swap(a, b);

      father[b] = a;
      sz[a] += sz[b];
      comps--;
    }
  }

  fout << ans;
}
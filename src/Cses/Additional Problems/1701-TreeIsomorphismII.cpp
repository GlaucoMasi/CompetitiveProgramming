#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int idx = 0, n;
map<vector<int>, int> m;

vector<int> centr(vector<int> g[]){
  vector<int> v;
  int degree[n] = {0};
  for(int i = 0; i < n; i++){
    degree[i] = g[i].size();
    if(degree[i] == 1) v.push_back(i), degree[i]--;
  }

  int done = v.size();
  while(done < n){
    vector<int> nxt;
    for(auto i : v){
      for(auto j : g[i]){
        degree[j]--;
        if(degree[j] == 1) nxt.push_back(j);
      }
    }

    done += nxt.size();
    v = nxt;
  }
  
  return v;
}

int hashing(int i, int p, vector<int> g[]){
  vector<int> curr;
  for(auto j : g[i]) if(j != p) curr.push_back(hashing(j, i, g));
  sort(curr.begin(), curr.end());
  if(!m.count(curr)) m[curr] = idx++;
  return m[curr];
}

bool solve() {
  cin >> n;
  vector<int> g[n], h[n];

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    g[--a].push_back(--b);
    g[b].push_back(a);
  }

  for(int i = 0; i < n-1; i++){
    int a, b; cin >> a >> b;
    h[--a].push_back(--b);
    h[b].push_back(a);
  }

  vector<int> c1 = centr(g), c2 = centr(h);

  for(int k = 0; c1.size() == c2.size() && k < c2.size(); k++) if(hashing(c1[0], -1, g) == hashing(c2[k], -1, h)) return 1;
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while(t--) cout << (solve() ? "YES\n" : "NO\n");
}
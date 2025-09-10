#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, k, need, idx = 0;
unordered_set<int> disp, forb;
unordered_map<string, int> comp;
vector<string> back;

bool done = 0;
vector<vector<int>> g;
vector<int> anc, status;

vector<int> topo;
vector<pair<int, int>> dp;

void f(int i){
  if(done || status[i] == 2) return;

  if(status[i] == 1){
    done = 1;

    int j = anc[i];
    vector<int> path; path.push_back(i);
    while(j != i){
      path.push_back(j);
      j = anc[j];
    }

    reverse(path.begin(), path.end());
    fout << back[path[0]].substr(0, min(need, (int)back[path[0]].size()));
    need -= min(need, (int)back[path[0]].size());
    
    int idx = 0;
    while(need){
      idx = (idx+1)%path.size();
      fout << back[path[idx]].back();
      need--;
    }

    status[i] = 2;
  }

  if(done) return;

  status[i] = 1;
  for(auto j : g[i]){
    anc[j] = i;
    f(j);
  }
  status[i] = 2;
  topo.push_back(i);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  fin >> n >> k >> need;
  
  for(int i = 0; i < n; i++){
    string a; fin >> a;

    for(int j = 0; j < a.size()-k+1; j++){
      string curr = a.substr(j, k);
      if(!comp.count(curr)) comp[curr] = idx++, back.push_back(curr);
      disp.insert(comp[curr]);
    }

    for(int j = 0; j < a.size()-k; j++){
      string curr = a.substr(j, k+1);
      if(!comp.count(curr)) comp[curr] = idx++, back.push_back(curr);
      forb.insert(comp[curr]);
    }
  }

  g.resize(idx);
  anc.resize(idx);
  status.resize(idx);
  for(auto i : disp){
    for(int j = 0; j < 26; j++){
      string bridge = back[i]+(char)('a'+j), nxt = bridge.substr(1, bridge.size()-1);
      if(comp.count(nxt) && disp.count(comp[nxt]) && (!comp.count(bridge) || !forb.count(comp[bridge]))) g[i].push_back(comp[nxt]);
    }
  }

  for(auto i : disp) if(status[i] != 2) f(i);

  if(!done){
    dp.resize(idx, {k, -1});

    for(auto i : topo) for(auto j : g[i]) dp[i] = max(dp[i], {dp[j].first+1, j});

    int i = max_element(dp.begin(), dp.end())-dp.begin();
    fout << back[i].substr(0, min(need, (int)back[i].size()));
    need -= min(need, (int)back[i].size());
    
    while(need){
      i = dp[i].second;
      fout << back[i].back();
      need--;
    }
  }
}
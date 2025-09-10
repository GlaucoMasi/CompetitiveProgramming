#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int idx = 1;
vector<unordered_map<string, int>> maps(1);
vector<bool> changed(1), toprint(1);

int get(){
  maps.push_back({});
  changed.push_back(0);
  toprint.push_back(0);
  return idx++;
}

bool dfs(int node){
  int tot = 0;
  for(auto [str, j] : maps[node]) tot += dfs(j);

  if(!maps[node].size()) toprint[node] = changed[node];
  else toprint[node] = (tot == maps[node].size());
  
  return toprint[node];
}

void print(int node, string path){
  if(toprint[node]){
    cout << (node ? path : "/") << '\n';
    return;
  }

  for(auto [str, j] : maps[node]) print(j, path+"/"+str);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n; i++){
    bool ch; cin >> ch;
    
    int node = 0;
    string path, curr; cin >> path;
    stringstream ss(path);
    while(getline(ss, curr, '/')){
      if(curr.empty()) continue;
      if(!maps[node].count(curr)) maps[node][curr] = get();
      node = maps[node][curr];
    }

    changed[node] = ch;
  }

  dfs(0);
  print(0, "");
}
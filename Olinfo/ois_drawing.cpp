#include <bits/stdc++.h>
using namespace std;

int n, m, e;
bool failure = 0;
vector<bool> done;
vector<vector<int>> g;
vector<vector<int>> ans(2);

vector<vector<int>> path(int node, int prec){
  vector<vector<int>> ans(2);
  if(failure) return ans;

  while(node != -1){
    done[node] = 1;
    ans[node >= n].push_back(node);
    
    int nextnode = -1;
    for(auto j : g[node]){
      if(j == prec) continue;
      
      if(done[j]){
        failure = 1;
        return ans;
      }

      if(g[j].size() == 1){
        done[j] = 1;
        ans[j >= n].push_back(j);
      }else if(nextnode == -1) nextnode = j;
      else{
        failure = 1;
        return ans;
      }
    }

    prec = node;
    node = nextnode;
  }

  return ans;
}

void first_node(int i){
  vector<vector<int>> middle(2), left(2), right(2);
  middle[i >= n].push_back(i);
  done[i] = 1;

  int complex = 0;
  for(auto j : g[i]){
    if(g[j].size() == 1){
      done[j] = 1;
      middle[j >= n].push_back(j);
    }else{
      complex++;
      if(complex == 1) right = path(j, i);
      else if(complex == 2) left = path(j, i);
      else failure = 1;
    }
  }

  for(int k = 0; k <= 1; k++){
    for(int i = left[k].size()-1; i >= 0; i--) ans[k].push_back(left[k][i]-n*k);
    for(int i = 0; i < middle[k].size(); i++) ans[k].push_back(middle[k][i]-n*k);
    for(int i = 0; i < right[k].size(); i++) ans[k].push_back(right[k][i]-n*k);
  }
}

int main(){
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m >> e;
  
  g.resize(n+m);
  done.resize(n+m);
  
  for(int i = 0; i < e; i++){
    int a, b; cin >> a >> b;
    g[a].push_back(b+n);
    g[b+n].push_back(a);
  }
  
  for(int i = 0; i < n && !failure; i++){
    if(done[i]) continue;

    int complex = 0;
    for(auto j : g[i]) if(g[j].size() > 1) complex++;

    if(complex > 2) failure = 1;
    else if(g[i].size() == 1) first_node(g[i][0]);
    else first_node(i);
  }

  for(int i = n; i < n+m; i++){
    if(done[i]) continue;
    ans[1].push_back(i-n);
  }
  
  if(failure) cout << -1;
  else{
    for(int k = 0; k <= 1; k++){
      for(int i = 0; i < ans[k].size(); i++) cout << ans[k][i] << " ";
      cout << '\n';
    }
  }
}
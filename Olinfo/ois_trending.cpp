#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

map<string, int> m;
vector<string> conv;

struct st{
  int size = 1;
  vector<pair<int, string>> v;

  st(int n){
    while(size < n) size *= 2;
    v.resize(2*size, {1e9, ""});
  }

  void upd(int i, int k){
    int u = size + i;
    v[u].first += k;

    while(u > 1){
      u /= 2;
      v[u] = min(v[2*u], v[2*u+1]);
    }
  }
};

int main() {
  int n, t; fin >> n >> t;
  vector<string> v(n);
  for(auto &i : v) fin >> i;

  for(auto &i : v){
    if(m.count(i)) continue;
    
    m[i] = conv.size();
    conv.push_back(i);
  }

  st st(conv.size());

  for(auto i : conv) st.v[st.size + m[i]] = {0, i};

  for(int i = 0; i < n; i++){
    st.upd(m[v[i]], -1);
    if(i-t >= 0) st.upd(m[v[i-t]], 1);
  
    if(i >= t-1) fout << st.v[1].second << endl;
  }
}
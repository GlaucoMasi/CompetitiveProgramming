#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<int> v;
vector<vector<pair<char, int>>> q;

void f(char c, int a, int i){
  if(v[a] == -1) q[a].push_back({c, i});
  else{
    if(c == 'P') v[i] = v[a] + 1;
    if(c == 'N') v[i] = v[a] + 2;
    if(c == 'B') v[i] = v[a] + 3;

    for(auto e : q[i]) f(e.first, i, e.second);
    q[i].clear();
  }
}

int main() {
  fin >> n;
  v.resize(n, -1);
  v[0] = 0;
  q.resize(n);

  for(int i = 1; i < n; i++){
    char c; int a;
    fin >> c >> a;
  
    f(c, a, i);
  }

  fout << *max_element(v.begin(), v.end());
}
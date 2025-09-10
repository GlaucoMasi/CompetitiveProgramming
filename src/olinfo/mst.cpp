#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

using type = pair<long long, pair<int, int>>;

int n, m;
vector<int> padre, size;
priority_queue<type, vector<type>, greater<type>> q;

int find(int a){
  int b = a;
  while(b != padre[b]) b = padre[b];

  return padre[a] = b;
}

void unione(int a, int b){
  a = find(a);
  b = find(b);

  if(size[b] > size[a]) swap(a, b);

  size[a] += size[b];
  padre[b] = a;
}

int main() {
  fin >> n >> m;

  padre.resize(n);
  size.resize(n, 1);

  for(int i = 0; i < m; i++){
    int a, b; long long c;
    fin >> a >> b >> c;
    a--; b--;

    q.push({c, {a, b}});

    if(i < n) padre[i] = i;
  }

  long long tot = 0;
  vector<pair<int, int>> lista;
  while(!q.empty()){
    auto curr = q.top(); q.pop();
    int a = curr.second.first;
    int b = curr.second.second;
    long long c = curr.first;
    
    if(find(a) != find(b)){ 
      unione(a, b);
    
      lista.push_back({a, b});  
      tot += c;
    }
  }

  fout << tot << endl;
  for(auto i : lista) fout << i.first+1 << " " << i.second+1 << endl;
}
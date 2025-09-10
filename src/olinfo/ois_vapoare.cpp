#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m, k, width;
vector<int> padre, size;

int find(int i){
  if(padre[i] == i) return i;
  return padre[i] = find(padre[i]);
}

bool check(pair<int, int> c){
  int a = find(c.first), b = find(c.second);

  if(a != b){
    if(size[a] < size[b]) swap(a, b);

    padre[b] = a;
    size[a] += size[b];
    return 1;
  }else return 0;
}

int main() {
  fin >> n >> m >> k;
  padre.resize(n);
  size.resize(n, 1);
  iota(padre.begin(), padre.end(), 0);

  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>> pq;
  int a, b, c;
  for(int i = 0; i < m; i++){
    fin >> a >> b >> c;
    a--; b--;
    pq.push({c, {a, b}});
  }

  int islands = n-1;
  vector<int> archi;
  while(!pq.empty()){
    auto curr = pq.top(); pq.pop();

    if(check(curr.second)){
      archi.push_back(curr.first);
      islands--;
    }
  }

  sort(archi.begin(), archi.end());
  while(k--){
    fin >> width;
    int count = lower_bound(archi.begin(), archi.end(), width) - archi.begin();
    fout << count+1+islands << endl;
  } 
}
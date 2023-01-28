#include<bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct st1{
  int size = 1;
  vector<int> v;

  void init(vector<int> &data){
    while(size < data.size()) size *= 2;
    v.resize(2*size); data.resize(size);
    build(1, 0, size, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1) v[u] = data[l];
    else{
      build(2*u, l, l + (r-l)/2, data);
      build(2*u+1, l + (r-l)/2, r, data);
      v[u] = max(v[2*u], v[2*u+1]);
    }
  }

  void upd(int pos, int k){
    int u = size+pos;
    v[u] = k;

    while(u > 1){
      u /= 2;
      v[u] = max(v[2*u], v[2*u+1]);
    }
  }

  int get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return v[u];
    return max(get(2*u, l, l + (r-l)/2, x, y), get(2*u+1, l + (r-l)/2, r, x, y));
  }
};

struct st2{
  int size = 1;
  vector<int> v;

  void init(vector<int> &data){
    while(size < data.size()) size *= 2;
    v.resize(2*size, 1e9);
    build(1, 0, size, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1){
      if(l < data.size()) v[u] = data[l];
    }else{
      build(2*u, l, l + (r-l)/2, data);
      build(2*u+1, l + (r-l)/2, r, data);
      v[u] = min(v[2*u], v[2*u+1]);
    }
  }

  void upd(int pos, int k){
    int u = size+pos;
    v[u] = k;

    while(u > 1){
      u /= 2;
      v[u] = min(v[2*u], v[2*u+1]);
    }
  }

  int get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 1e9;
    if(l >= x && r <= y) return v[u];
    return min(get(2*u, l, l + (r-l)/2, x, y), get(2*u+1, l + (r-l)/2, r, x, y));
  }
};

st1 magg;
st2 succ;
vector<set<int>> occ;
vector<int> after, v;

void inizio(int n, int m, int sfere[]){
  v.resize(n);
  for(int i = 0; i < n; i++) v[i] = sfere[i]-1;

  magg.init(v);
  occ.resize(n);
  after.resize(n, n);
  
  for(int i = 0; i < n; i++) occ[v[i]].insert(i);
  
  for(int i = 0; i < n; i++){
    auto t = occ[v[i]].find(i); t = next(t);
    if(t != occ[v[i]].end()) after[i] = *t;
  }

  succ.init(after);
}

void modifica(int pos, int val){
  val--;
  magg.upd(pos, val);

  auto t = occ[v[pos]].find(pos);
  if(t != occ[v[pos]].begin()) succ.upd(*prev(t), (next(t) == occ[v[pos]].end() ? v.size() : *next(t)));

  occ[v[pos]].erase(occ[v[pos]].find(pos));
  v[pos] = val;
  occ[v[pos]].insert(pos);

  t = occ[v[pos]].find(pos);
  if(t != occ[v[pos]].begin()) succ.upd(*prev(t), pos);

  if(next(t) != occ[v[pos]].end()) succ.upd(pos, *next(t));
  else succ.upd(pos, v.size());
}

bool verifica(int l, int r){
  int first_check = magg.get(1, 0, magg.size, l, r+1);
  if(first_check != r-l) return 0;

  int second_check = succ.get(1, 0, succ.size, l, r+1);
  if(second_check <= r) return 0;

  return 1;
}

int main() {
  const int MAXN = 1e5;
  const int MAXM = 1e5;
	int sfere[MAXN], N, M;
	fin>>N>>M;
	for(int i=0;i<N;i++)
		fin>>sfere[i];
	inizio(N, M, sfere);
	for(int i=0;i<M;i++){
		int tipo, a, b;
		fin>>tipo>>a>>b;
		if(tipo==1)
			fout<<(int)verifica(a,b) << endl;
		else modifica(a,b);
	}
	return 0;
}
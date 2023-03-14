#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

constexpr int num = 2e7;

struct node{
  long long val = 0, lazy = 0;
  int left = -1, right = -1;

  node() {}
};

static node nodes[num];

struct ST{
  int size, curr = 0;
  vector<int> roots;

  int gen(){ return curr++; }
  
  int copy(int prev){
    nodes[curr] = nodes[prev];
    return curr++;
  }
 
  void lazyadd(int u, int l, int r, long long k){
    nodes[u].val += k*(r-l);
    nodes[u].lazy += k;
  }

  void passa(int u, int l, int r){
    if(!nodes[u].lazy) return;

    if(nodes[u].left != -1){
      nodes[u].left = copy(nodes[u].left);
      lazyadd(nodes[u].left, l, l + (r-l)/2, nodes[u].lazy);
    }

    if(nodes[u].right != -1){
      nodes[u].right = copy(nodes[u].right);
      lazyadd(nodes[u].right, l + (r-l)/2, r, nodes[u].lazy);
    }

    nodes[u].lazy = 0;
  }

  void init(vector<int> &data){
    for(size = 1; size < data.size(); size *= 2);
    data.resize(size);

    roots.push_back(build(0, size, data));
  }

  int build(int l, int r, vector<int> &data){
    int i = gen();

    if(l == r-1) nodes[i].val = data[l];
    else{
      nodes[i].left = build(l, l + (r-l)/2, data);
      nodes[i].right = build(l + (r-l)/2, r, data);
      nodes[i].val = nodes[nodes[i].left].val + nodes[nodes[i].right].val;
    }

    return i;
  }

  long long get(int u, int l, int r, int x, int y){
    passa(u, l, r);

    if(l >= y || r <= x) return 0;
    if(l >= x && r <= y) return nodes[u].val;

    return get(nodes[u].left, l, l + (r-l)/2, x, y) + get(nodes[u].right, l + (r-l)/2, r, x, y);
  }

  int add(int prev, int l, int r, int x, int y, int k){
    passa(prev, l, r);

    if(l >= y || r <= x) return prev;

    int i = copy(prev);

    if(l >= x && r <= y) lazyadd(i, l, r, k);
    else{ 
      nodes[i].left = add(nodes[prev].left, l, l + (r-l)/2, x, y, k);
      nodes[i].right = add(nodes[prev].right, l + (r-l)/2, r, x, y, k);
      nodes[i].val = nodes[nodes[i].left].val + nodes[nodes[i].right].val;
    }
    
    return i;
  }

  int set(int prev, int old, int l, int r, int x, int y){
    passa(prev, l, r);
    passa(old, l, r);

    if(l >= y || r <= x) return copy(prev);
    if(l >= x && r <= y) return copy(old);

    int i = gen();
    nodes[i].left = set(nodes[prev].left, nodes[old].left, l, l + (r-l)/2, x, y);
    nodes[i].right = set(nodes[prev].right, nodes[old].right, l + (r-l)/2, r, x, y);
    nodes[i].val = nodes[nodes[i].left].val + nodes[nodes[i].right].val;
    return i;
  }
};

ST st;

void inizia(int N, vector<int> A){ st.init(A); }
void incrementa(int l, int r, int x){ st.roots.push_back(st.add(st.roots.back(), 0, st.size, l, r, x)); }
void resetta(int l, int r, int v){ st.roots.push_back(st.set(st.roots.back(), st.roots[v], 0, st.size, l, r)); }
long long somma(int l, int r) { return st.get(st.roots.back(), 0, st.size, l, r); }
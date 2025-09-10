#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct st{
  int n, size = 1;
  vector<int> v;

  st(vector<int> &data){
    while(size < data.size()) size *= 2;
    v.resize(2*size, -1e9);
    n = data.size();

    build(1, 0, size, data);
  }

  void build(int u, int l, int r, vector<int> &data){
    if(l == r-1){
      if(l < data.size()) v[u] = data[l];
    }else{
      build(2*u, l, l + (r-l)/2, data);
      build(2*u+1, l + (r-l)/2, r, data);

      v[u] = max(v[2*u], v[2*u+1]);
    }
  }

  int find_left(int u, int l, int r, int x, int y, int k){
    if(l >= y || r <= x) return -1;
    if(l >= x && r <= y){
      if(v[u] < k) return -1;
      else{
        if(l == r-1) return l;

        if(v[2*u+1] >= k) return find_left(2*u+1, l + (r-l)/2, r, x, y, k);
        else return find_left(2*u, l, l + (r-l)/2, x, y, k);
      }
    }

    auto temp = find_left(2*u+1, l + (r-l)/2, r, x, y, k);
    if(temp != -1) return temp;
    else return find_left(2*u, l, l + (r-l)/2, x, y, k);
  }

  int find_right(int u, int l, int r, int x, int y, int k){
    if(l >= y || r <= x) return -1;
    if(l >= x && r <= y){
      if(v[u] < k) return -1;
      else{
        if(l == r-1) return l;

        if(v[2*u] >= k) return find_right(2*u, l, l + (r-l)/2, x, y, k);
        else return find_right(2*u+1, l + (r-l)/2, r, x, y, k);
      }
    }

    auto temp = find_right(2*u, l, l + (r-l)/2, x, y, k);
    if(temp != -1) return temp;
    else return find_right(2*u+1, l + (r-l)/2, r, x, y, k);
  }

  int ans(int i, int k){
    int r = find_right(1, 0, size, i+1, n, k);
    int l = find_left(1, 0, size, 0, i, k); 

    return (r == -1 ? n-1 : r) - (l == -1 ? 0 : l) + 1;
  }
};

int main() {
  int n; fin >> n;
  vector<int> v(n);
  for(auto &i : v) fin >> i;

  st st(v);
  int best = 0;
  for(int i = 0; i < n; i++) best = max(best, st.ans(i, v[i]));

  fout << best;
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct ST{
  struct Node{
    int val = 0;

    Node(int a){
      val = a;
    }

    void join(const Node &l, const Node &r){
      val = min(l.val, r.val);
    }
  };

  int size = 1;
  vector<Node> v;
  ST(int n){
    while(size < n) size *= 2;
    v.resize(2*size, Node(0));
  }

  void update(int pos, int k){
    int u = size + pos;
    v[u].val = k;

    while(u > 1){
      u /= 2;
      v[u].join(v[2*u], v[2*u+1]);
    }
  }

  int get(int u, int l, int r, int x, int y){
    if(l >= y || r <= x) return 1e9;
    if(l >= x && r <= y) return v[u].val;

    return min(
      get(2*u, l, l + (r-l)/2, x, y),
      get(2*u+1, l + (r-l)/2, r, x, y)
    );
  }
};

int salta(int N, vector<int> S, vector<int> A, vector<int> B){
  N++;
  ST st(N);

  for(int i = N-2; i >= 0; i--){
    int ans = max(S[i], st.get(1, 0, st.size, i+A[i], i+B[i]+1));
    st.update(i, ans);
  }

  return st.v[st.size].val;
}
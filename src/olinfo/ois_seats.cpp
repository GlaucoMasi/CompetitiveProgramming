#include <bits/stdc++.h>
using namespace std;

struct st{
  int size = 1;
  vector<int> v;

  st(int n){
    while(size < n) size *= 2;
    v.resize(2*size);
  }

  void upd(int pos){
    int u = size+pos;
    v[u]++; v[u] %= 2;

    while(u > 1){
      u /= 2;
      v[u] = v[2*u]+v[2*u+1];
    }
  }

  int get(int u, int son){
    if(son == 0) return u-size;

    if(v[2*u] == son) return get(2*u+1, son/2);
    else return get(2*u, son/2);
  }
};

int main() {
  int n, q;
  cin >> n >> q;

  st st(n);

  vector<int> pos(n, -1);
  vector<int> res(n, -1);

  int ans = 0;

  while(q--){
    char c; int a;
    cin >> c >> a;

    if(c == 'b'){
      int first = st.get(1, st.size/2);

      if(first < a){
        st.upd(first);
        res[first] = a;
        pos[a] = first;
      }else{
        while(1){
          if(res[a] == -1){
            st.upd(a);
            res[a] = a;
            pos[a] = a;
            
            break;
          }else{
            int next = res[a];
            res[a] = a;
            pos[a] = a;
            a = next;
            ans++;
          }
        }
      }
    }else{
      st.upd(pos[a]);
      res[pos[a]] = -1;
      pos[a] = -1;
    }
  }

  cout << ans;
}
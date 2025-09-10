#include <bits/stdc++.h>
using namespace std;

int n, m, q, ans = 0;
vector<int> fat, tree, anc, treesz;

int get(int i){
  if(i == -1 || i == fat[i]) return i;
  else return fat[i] = get(fat[i]);
}

void merge(int a, int b){
  fat[b] = a;
}

int gettree(int i){
  if(i == tree[i]) return i;
  else return tree[i] = gettree(tree[i]);
}

void inv(int i, int f){
  if(i == -1) return;
  inv(get(anc[i]), i);
  anc[i] = f; tree[i] = f;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n >> m >> q;
  fat.resize(n); iota(fat.begin(), fat.end(), 0);
  tree.resize(n); iota(tree.begin(), tree.end(), 0);
  treesz.resize(n, 1); anc.resize(n, -1);

  for(int i = 0; i < m+q; i++){
    int a, b; cin >> a >> b; a--; b--;
    get(a); get(b);

    if(fat[a] != fat[b]){
      a = fat[a]; b = fat[b]; gettree(a); gettree(b);
      if(tree[a] == tree[b]){
        vector<bool> vis(n);

        int lca = -1, t1 = a, t2 = b;
        while(lca == -1){
          if(t1 != -1){
            if(vis[t1]) lca = t1;
            vis[t1] = 1;
            t1 = get(anc[t1]);
          }

          if(t2 != -1){
            if(vis[t2]) lca = t2;
            vis[t2] = 1;
            t2 = get(anc[t2]);
          }
        }

        while(a != lca){
          merge(lca, a);
          ans--;
          a = get(anc[a]);
        }

        while(b != lca){
          merge(lca, b);
          ans--;
          b = get(anc[b]);
        }
      }else{
        if(treesz[tree[a]] < treesz[tree[b]]) swap(a, b);
        inv(get(anc[b]), b); anc[b] = a;
        treesz[tree[a]] += treesz[tree[b]]; tree[b] = a;
        ans++;
      }
    }

    if(i >= m) cout << ans << '\n';
  }
}
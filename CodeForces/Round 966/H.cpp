#include <bits/stdc++.h>
using namespace std;
ofstream fout("output.txt");

struct loadedset{
  struct node{
    int prior, ans;
    pair<int, int> val;
    node *l, *r;
  
    node(pair<int, int> t){
      prior = rand();
      val = t;
      ans = t.second;
      l = r = nullptr;
    }
  };

  void print(node* treap){
    if(!treap) return;
    fout << treap->val.first << " " << treap->val.second << '\n';
    print(treap->l);
    print(treap->r);
  }

  int get(node* t){
    if(!t) return 1e9;
    else return t->ans;
  }

  void update(node* t){
    if(!t) return;
    t->ans = min({t->val.second, get(t->l), get(t->r)});
  }

  void split(node* a, node* &t1, node* &t2, pair<int, int> k){
    if(!a) t1 = t2 = nullptr;
    else if(a->val <= k){
      split(a->r, a->r, t2, k);
      t1 = a;
    }else{
      split(a->l, t1, a->l, k);
      t2 = a;
    }

    update(t1);
    update(t2);
  }

  void merge(node* a, node* b, node* &t){
    if(!a) t = b;
    else if(!b) t = a;
    else if(a->prior > b->prior){
      merge(a->r, b, a->r);
      t = a;
    }else{
      merge(a, b->l, b->l);
      t = b;
    }

    update(t);
  }

  set<int> pres;
  node* treap = nullptr;
  node *t1, *t2;

  loadedset(){
    pres.insert(0);
    pres.insert(1e9);
    addhelp(1e9-1, 1);
  }

  void addhelp(int k, int i){
    node* nodei = new node({k, i});
    split(treap, treap, t1, {k, i});
    merge(treap, nodei, treap);
    merge(treap, t1, treap);
  }

  void remhelp(int k, int i){
    split(treap, treap, t1, {k, i-1});
    split(t1, t1, t2, {k, i});
    merge(treap, t2, treap);
  }

  void add(int k){
    pres.insert(k);
    auto t = pres.lower_bound(k);
    int l = *prev(t), r = *next(t);
    remhelp(r-l-1, l+1);
    if(k != l+1) addhelp(k-l-1, l+1);
    if(k != r-1) addhelp(r-k-1, k+1);
  }

  void remove(int k){
    auto t = pres.lower_bound(k);
    int l = *prev(t), r = *next(t);
    addhelp(r-l-1, l+1);
    if(k != l+1) remhelp(k-l-1, l+1);
    if(k != r-1) remhelp(r-k-1, k+1);
    pres.erase(t);
  }

  int query(int k){
    split(treap, treap, t1, {k-1, 1e9});
    int ans = t1->ans;
    merge(treap, t1, treap);
    return ans;
  }
};

void solve() {
  int n; cin >> n;
  loadedset str;
  while(n--){
    int a; cin >> a;
    str.add(a);
  }

  int m; cin >> m;
  while(m--){
    char c; int x;
    cin >> c >> x;

    if(c == '+') str.add(x);
    else if(c == '-') str.remove(x);
    else cout << str.query(x) << " ";
  }

  cout << '\n';
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t = 1;
  cin >> t;
  while(t--) solve();
}
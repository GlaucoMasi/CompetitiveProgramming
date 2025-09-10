#include <bits/stdc++.h>
using namespace std;

struct treap{
  treap *l = nullptr, *r = nullptr;
  int sz = 1, pr;
  long long val = 0, sum = 0;
  bool inv = 0;
};

void upd(treap* &t){
  if(t == nullptr) return;

  if(t->inv){
    swap(t->l, t->r);
    if(t->l) t->l->inv ^= 1;
    if(t->r) t->r->inv ^= 1;

    t->inv = 0;
  }

  t->sz = 1 + (t->l ? t->l->sz : 0) + (t->r ? t->r->sz : 0);
  t->sum = t->val + (t->l ? t->l->sum : 0LL) + (t->r ? t->r->sum : 0LL);
}

void merge(treap* a, treap* b, treap* &t){
  upd(a); upd(b);

  if(a == nullptr) t = b;
  else if(b == nullptr) t = a;
  else{
    if(a->pr > b->pr){
      merge(a->r, b, a->r);
      t = a;
    }else{
      merge(a, b->l, b->l);
      t = b;
    }
  }

  upd(t);
}

void split(treap* a, treap* &t1, treap* &t2, int k){
  upd(a);
  
  if(a == nullptr){
    t1 = nullptr;
    t2 = nullptr;
    return;
  }

  int szl = (a->l ? a->l->sz : 0);

  if(szl >= k){
    split(a->l, t1, a->l, k);
    t2 = a;
  }else{
    split(a->r, a->r, t2, k-szl-1);
    t1 = a;
  }

  upd(t1); upd(t2);
}

int main() {
  int n, q; cin >> n >> q;
  vector<int> v(n); for(auto &i : v) cin >> i;

  treap* tr = nullptr;
  for(int i = 0; i < n; i++){
    treap* temp = new treap;
    temp->val = temp->sum = v[i];
    temp->pr = rand();
    merge(tr, temp, tr);
  }

  treap *t1 = nullptr, *t2 = nullptr;
  while(q--){
    int t, l, r; cin >> t >> l >> r;
    split(tr, t1, tr, l-1);
    split(tr, tr, t2, r-l+1);

    if(t == 1){
      tr->inv ^= 1;
      upd(tr);
    }else cout << tr->sum << '\n';

    merge(t1, tr, tr);
    merge(tr, t2, tr);
  }
}
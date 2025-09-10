#include <bits/stdc++.h>
using namespace std;

struct treap{
  treap *l = nullptr, *r = nullptr;
  int pr, sz = 1;
  bool rev = 0;
  char c;
};

void upd(treap *&a){
  if(!a) return;

  if(a->rev){
    swap(a->l, a->r);
    if(a->l) a->l->rev ^= 1;
    if(a->r) a->r->rev ^= 1;
    a->rev = 0;
  }

  a->sz = 1 + (a->l ? a->l->sz : 0) + (a->r ? a->r->sz : 0);
}

void merge(treap *a, treap *b, treap *&t){
  upd(a); upd(b);

  if(!a || !b) t = (a ? a : b);
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

void split(treap *a, treap *&t1, treap *&t2, int k){
  upd(a);
  
  if(!a){
    t1 = t2 = nullptr;
    return;
  }

  int szl = a->l ? a->l->sz : 0;
  if(szl >= k){
    split(a->l, t1, a->l, k);
    t2 = a;
  }else{
    split(a->r, a->r, t2, k-szl-1);
    t1 = a;
  }

  upd(t1); upd(t2);
}

void print(treap *a){
  if(!a) return;
  upd(a);

  print(a->l);
  cout << a->c;
  print(a->r);
}

int main() {
  int n, q; cin >> n >> q;  
  string t; cin >> t;

  treap *tr = nullptr;
  for(int i = 0; i < n; i++){
    treap *temp = new treap;
    temp->c = t[i];
    temp->pr = rand();
    merge(tr, temp, tr);
  }

  treap *t1 = nullptr, *t2 = nullptr;
  while(q--){
    int l, r; cin >> l >> r;
    split(tr, t1, tr, l-1);
    split(tr, tr, t2, r-l+1);

    tr->rev ^= 1;
    upd(tr);

    merge(t1, tr, tr);
    merge(tr, t2, tr);
  }

  print(tr);
}
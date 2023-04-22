#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;

struct node{
  int val, size, priority;
  node *l, *r;

  node(int k){
    val = k;
    size = 1;
    priority = rand();
    l = nullptr; r = nullptr;
  }
};

int sz(node *treap){ return (treap) ? treap->size : 0; }

void upd(node *&treap){ if(treap) treap->size = sz(treap->l) + sz(treap->r) + 1; }

void fix(node *&treap){
  if(!treap) return;
  node *t = treap;

  if(treap->l && treap->l->priority > t->priority) t = treap->l;
  if(treap->r && treap->r->priority > t->priority) t = treap->r;

  if(t != treap){
    swap(treap->priority, t->priority);
    fix(t);
  }
}

void build(node *&treap, int l, int r){
  if(l == r) return;
  
  treap = new node(l + (r-l)/2);

  if(l == r-1) return;

  build(treap->l, l, l + (r-l)/2);
  build(treap->r, l + (r-l)/2 + 1, r);

  fix(treap);
  upd(treap);
}

int get(node *treap, int k){
  int curr = sz(treap->l);

  if(k == curr) return treap->val;
  else if(k < curr) return get(treap->l, k);
  else return get(treap->r, k-curr-1);
}

void split(node *treap, node *&ans1, node *&ans2, int k){
  if(!treap){
    ans1 = nullptr;
    ans2 = nullptr;
    return;
  }

  int curr = sz(treap->l);
  if(curr <= k){
    ans1 = treap;
    split(ans1->r, ans1->r, ans2, k-curr-1);
  }else{
    ans2 = treap;
    split(ans2->l, ans1, ans2->l, k);
  }

  upd(ans1); upd(ans2);
}

void merge(node *t1, node *t2, node *&ans){  
  if(!t1){
    ans = t2;
    return;
  }else if(!t2){
    ans = t1;
    return;
  }

  if(t1->priority > t2->priority){
    ans = t1;
    merge(ans->r, t2, ans->r);
  }else{
    ans = t2;
    merge(t1, ans->l, ans->l);
  }

  upd(ans);
}

int main() {
  fin >> n >> m;

  node *treap;
  build(treap, 0, n);

  while(m--){
    char c; fin >> c;

    node *ans1, *ans2, *ans3, *ans4;

    if(c == 'c'){
      int i; fin >> i;
      fout << get(treap, i) << " ";
    }else{
      int i, j; fin >> i >> j;

      split(treap, ans1, ans3, i);
      split(ans1, ans1, ans2, i-1);

      merge(ans1, ans3, ans1);
      split(ans1, ans1, ans3, j-1);
      merge(ans1, ans2, ans1);
      merge(ans1, ans3, ans1);

      treap = ans1;
    }
  }
}
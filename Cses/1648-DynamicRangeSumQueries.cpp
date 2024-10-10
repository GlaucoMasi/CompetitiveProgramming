#include <bits/stdc++.h>
using namespace std;

struct Fen{
  vector<long long> ft;

  void build(int n){ ft.resize(n+1, 0); }

  void add(int p, int v){
    for(p++; p < ft.size(); p += p&-p)
      ft[p] += v;
  }

  long long pref(int b){
    long long res = 0;
    for(b++; b > 0; b -= b&-b){
      res += ft[b];
    }
    return res;
  }

  long long sum(int a, int b){
    return pref(b) - (a ? pref(a-1) : 0);
  }

  void update(int p, int v){
    add(p, v-sum(p, p));
  }
};

int main() {
  int n, m; cin >> n >> m;

  Fen ft;
  ft.build(n);

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    ft.add(i, a);
  }

  for(int i = 0; i < m; i++){
    int a, b, c;
    cin >> a >> b >> c;
    b--;

    if(a == 1) ft.update(b, c);
    else cout << ft.sum(b, c-1) << endl;
  }
}
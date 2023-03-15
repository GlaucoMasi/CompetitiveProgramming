#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void Bake(int i);

int order_num = 0;
vector<list<int>> v(257);
vector<int> ingr(8, 0);
int available = 0;

void Init() { return; }

void check() {
  pair<int, int> ans = {1e9, 300};

  for(int i = 0; i <= 256; i++) if(!v[i].empty()) if(!(available&i^i)) ans = min(ans, {v[i].front(), i});
  
  if(ans.first != 1e9){
    Bake(ans.first);
    v[ans.second].pop_front();

    for(int i = 0; i <= 7; i++){
      if(!(ans.second&(1<<i))) continue;
      
      ingr[i]--;
      if(!ingr[i]) available &= ~(1<<i);
    }
  }
}

void Order(int N, int *A) {
  int temp = 0;
  for(int i = 0; i < N; i++) temp |= (1<<A[i]);

  if(!(available&temp^temp)){
    Bake(order_num);

    for(int i = 0; i < N; i++){
      ingr[A[i]]--;
      
      if(!ingr[A[i]]) available &= ~(1<<A[i]);
    }
  }else v[temp].push_back(order_num);
  
  order_num++;
}

void Delivery(int I) {
  ingr[I]++;
  available |= (1<<I);

  check();
}
#include <bits/stdc++.h>
using namespace std;

void stato();
void sposta();
bool chiedi(int K);

void indovina(int n, int a, int b, int c, int h[]){
  if(b == 1){
    int pos = 0;
    int block = sqrt(n), num = n/block;
    if(block*num < n) num++;
    
    set<int> v; for(int i = 0; i < n; i++) v.insert(i);
    vector<set<int>> pres(num);

    for(int i = 0; i < num; i++){
      while(pos < block*(i+1)-1 && pos+1 < n){
        sposta();
        pos++;
      }
      
      for(auto j : v) if(chiedi(j)) pres[i].insert(j);
      for(auto j : pres[i]) v.erase(j);
    }

    stato();
    sposta();

    for(int i = n-1; i >= 1; i--){
      int curr = i/block;

      for(auto j : pres[curr]) if(!chiedi(j)){
        h[i] = j;
        pres[curr].erase(h[i]);
        break;
      }

      if(i != 1) sposta();
    }

    h[0] = *pres[0].begin();
  }else{
    int curr = 0; bool state = 1, side = 0;
    priority_queue<array<int, 3>> pq, next;
    for(int i = 0; i < n; i++) pq.push({1, -n+1, i});

    while(1){
      while(!next.empty()) next.pop();

      while(!pq.empty()){
        auto [l, r, i] = pq.top(); pq.pop();
        
        if(!side){ l *= -1; r *= -1; }

        if(l >= r-1) h[l+1] = i;
        else{
          int m = (l+r)/2;

          if(m > curr){
            if(!state){
              stato();
              state = 1;
            }

            while(curr < m){
              sposta();
              curr++;
            }
          }else if(m < curr){
            if(state){
              stato();
              state = 0;
            }

            while(curr > m){
              sposta();
              curr--;
            }
          }

          if(chiedi(i)) r = m;
          else l = m;
          
          if(side) next.push({-l, -r, i});
          else next.push({l, r, i});
        }
      }

      if(next.empty()) break;
      pq = next; side ^= 1;
    }
  } 
}
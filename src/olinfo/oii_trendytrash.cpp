#include <bits/stdc++.h>
using namespace std;

struct s{
  int zero = 0, uno = 0;
};

int n, m, tot_r, tot_c;
long long tot;
s off_r, off_c;
vector<s> rig, col;
queue<int> righe, colonne;


int pulisci(int N, int M, vector<string> S){
  n = N, m = M;
  rig.resize(n);
  col.resize(m);

  tot = n*m;
  tot_r = m;
  tot_c = n;

  for(int i = 0; i < n; i++){
    righe.push(i);
  
    for(int j = 0; j < m; j++){
      if(i == 0) colonne.push(j);
      char curr = S[i][j];
      
      if(curr == '0'){
        rig[i].zero++;
        col[j].zero++;
      }else{
        rig[i].uno++;
        col[j].uno++;
      }
    }  
  }

  bool done = 1;
  while(done){
    done = 0;
    
    for(int i = 0; i < tot_c; i++){
      int curr = righe.front();
      righe.pop();

      if(rig[curr].zero - off_r.zero == tot_r){
        tot -= tot_r;
        tot_c--;
        done = 1;
        off_c.zero++;
      }else if(rig[curr].uno - off_r.uno == tot_r){
        tot -= tot_r;
        tot_c--;
        done = 1;
        off_c.uno++;
      }else righe.push(curr);
    }

    for(int i = 0; i < tot_r; i++){
      int curr = colonne.front();
      colonne.pop();

      if(col[curr].zero - off_c.zero == tot_c){
        tot -= tot_c;
        tot_r--;
        done = 1;
        off_r.zero++;
      }else if(col[curr].uno - off_c.uno == tot_c){
        tot -= tot_c;
        tot_r--;
        done = 1;
        off_r.uno++;
      }else colonne.push(curr);
    }
  }

  return tot;
}
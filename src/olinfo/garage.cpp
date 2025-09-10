#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, m;
int tot = 0;
vector<int> par, mac, parmac, macpar;
queue<int> q;

// parmac -> parcheggio di macchina
// macpar -> macchina in parceggio

void enter(int j){
  bool trovato = false;

  for(int i = 0; i < n && !trovato; i++){
    if(macpar[i] == -1){
      parmac[j] = i;
      macpar[i] = j;

      trovato = true;

      tot += par[i] * mac[j];
    }
  }

  if(!trovato) q.push(j);
}

void leave(int j){
  int parc = parmac[j];

  parmac[j] = -1;
  macpar[parc] = -1;

  if(!q.empty()){
    int front = q.front();
    q.pop();

    parmac[front] = parc;
    macpar[parc] = front;

    tot += par[parc] * mac[front];
  }
}

int main() {
  fin >> n >> m;

  par.resize(n);
  macpar.resize(n, -1);
  for(int i = 0; i < n; i++) fin >> par[i];

  mac.resize(m);
  parmac.resize(m, -1);
  for(int i = 0; i < m; i++) fin >> mac[i];

  for(int i = 0; i < 2*m; i++){
    int temp;
    fin >> temp;

    if(temp > 0) enter(abs(temp) - 1);
    else leave(abs(temp) - 1);
  }

  fout << tot;
}
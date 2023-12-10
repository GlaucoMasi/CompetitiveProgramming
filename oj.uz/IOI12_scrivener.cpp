#include <bits/stdc++.h>
using namespace std;

int idx = 0;
struct node{
  char c;
  vector<int> fat;
  int size;
};
vector<node> v(1e6+5);

void Init(){
  v[0].c = '0';
  v[0].size = 0;
}

void TypeLetter(char l){
  idx++;
  v[idx].c = l;
  v[idx].size = v[idx-1].size+1;
  
  v[idx].fat.push_back(idx-1);
  for(int i = 1; 1; i++){
    if(i-1 >= v[v[idx].fat[i-1]].fat.size()) break;
    v[idx].fat.push_back(v[v[idx].fat[i-1]].fat[i-1]);
  }
}

void UndoCommands(int u){
  idx++;
  v[idx] = v[idx-u-1];
}

char GetLetter(int p){
  p = v[idx].size-p-1; int temp = idx;
  int l = log2(p)+2;
  for(int i = l; i >= 0; i--){
    if((p & (1<<i)) && v[temp].fat.size() > i) temp = v[temp].fat[i];
  }

  return v[temp].c;
}
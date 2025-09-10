#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; long long k; fin >> n >> k;

  vector<int> comp;
  map<long long, int> add;
  
  for(int i = 0; i < n; i++){
    long long l, r; fin >> l >> r;
    comp.push_back(l); comp.push_back(r+1);
    add[l]++; add[r+1]--;
  }

  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end())-comp.begin());

  long long open = 0, tot = 0;
  for(int i = 0; i < comp.size(); i++){
    open += add[comp[i]];

    long long next = (comp[i+1]-comp[i])*open;
    if(tot+next < k) tot += next;
    else{
      fout << comp[i]+(k-tot-1)/open;
      break;
    }
  }
}
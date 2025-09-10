#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, tot;
vector<int> v;

void f(int i, int temp, int totale, vector<int> curr){
  if(i == n){
    if(temp + totale == tot){
      for(int i = 0; i < curr.size(); i++) fout << curr[i]+1 << " ";
      fout << endl;
    }

    return;
  }

  if(totale + temp > tot) return;

  f(i+1, temp*10 + v[i], totale, curr);

  curr.push_back(i-1);
  f(i+1, v[i], totale + temp, curr);
  curr.pop_back();
}

int main() {
  fin >> n;
  v = vector<int>(n);
  for(auto &i : v) fin >> i;
  fin >> tot;

  vector<int> ans;
  f(1, v[0], 0, ans);
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int mod = 1e9+7;
const int maxn = 1e5+1;
int fen[maxn];

void add(int i, int k){
  i++;
  while(i < maxn){
    fen[i] = (fen[i]+k)%mod;
    i += (i&-i);
  }
}

int get(int i){
  i++;
  int ans = 0;
  while(i > 0){
    ans = (ans+fen[i])%mod;
    i -= (i&-i);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; fin >> n;
  vector<int> v(n); for(auto &i : v) fin >> i;

  vector<int> comp = v;
  sort(comp.begin(), comp.end());
  comp.resize(unique(comp.begin(), comp.end())-comp.begin());
  unordered_map<int, int> m;
  for(int i = 0; i < comp.size(); i++) m[comp[i]] = i;
  for(auto &i : v) i = m[i];

  int tot = 0;
  for(int i = 0; i < n; i++){
    int curr = (get(v[i]-1)+1)%mod;
    tot = (tot+curr)%mod;
    add(v[i], curr);
  }

  fout << tot;
}
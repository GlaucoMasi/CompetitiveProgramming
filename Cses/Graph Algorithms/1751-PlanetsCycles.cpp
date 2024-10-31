#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
vector<int> nxt, len, status, fat, ans;

void f(int i){
  if(status[i] == 1){
    int j = i;
    vector<int> path;
    do{
      path.push_back(j);
      j = fat[j];
    }while(j != i);

    for(auto i : path) len[i] = path.size();

    status[i] = 2;
    return;
  }

  status[i] = 1;

  if(status[nxt[i]] != 2){
    fat[nxt[i]] = i;
    f(nxt[i]);
  } 

  status[i] = 2;
}

int calc(int i){
  if(ans[i] != -1) return ans[i];
  if(len[i] != -1) return ans[i] = len[i];
  return ans[i] = calc(nxt[i])+1;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  cin >> n;
  nxt.resize(n);
  fat.resize(n);
  status.resize(n);
  len.resize(n, -1);
  ans.resize(n, -1);
  for(auto &i : nxt) cin >> i, i--;

  for(int i = 0; i < n; i++) if(!status[i]) f(i);
  for(int i = 0; i < n; i++) cout << calc(i) << " ";
}
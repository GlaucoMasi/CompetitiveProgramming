#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5+2;
int fen[maxn], tot = 0;

void add(int i){
  i++; tot++;
  while(i < maxn){
    fen[i]++;
    i += (i&-i);
  }
}

int get(int i){
  int ans = tot;
  while(i > 0){
    ans -= fen[i];
    i -= (i&-i);
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  for(int i = 0; i < n; i++){
    int a; cin >> a;
    cout << 2*get(a)+a-i-1 << " ";
    add(a);
  }
}
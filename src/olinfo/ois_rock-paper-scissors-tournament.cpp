#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, m; cin >> n >> m;
  
  int v[2][2] = {0}, biggest[2] = {0, 0}, smallest[2] = {INF, INF};
  long long tot = 0;
  vector<int> forw, ord[2];
  unordered_map<int, int> freq;

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    tot += freq[a]++;
    v[a>0][abs(a)%2]++;
    if(a < 0){
      ord[abs(a)%2].push_back(abs(a));
      biggest[abs(a)%2] = max(biggest[abs(a)%2], abs(a));
      smallest[abs(a)%2] = min(smallest[abs(a)%2], abs(a));
    }else forw.push_back(a);
  }

  tot += (long long)v[0][0]*v[1][0];
  tot += (long long)v[0][1]*v[1][1];
  if(m%2){
    tot += (long long)v[0][0]*v[1][1];
    tot += (long long)v[0][1]*v[1][0];    
  }

  for(int i = 0; i < 2; i++) sort(ord[i].begin(), ord[i].end());

  int lastmatch = 0;

  if(tot){
    for(auto i : forw){
      if(biggest[i%2] > i) lastmatch = max(lastmatch, (biggest[i%2]-i)/2);
      if(m%2 && biggest[(i+1)%2]) lastmatch = max(lastmatch, (m-i+biggest[(i+1)%2])/2);
      if(smallest[i%2] < i){
        while(lower_bound(ord[i%2].begin(), ord[i%2].end(), i) == ord[i%2].begin()) tot++;
        int pos = *prev(lower_bound(ord[i%2].begin(), ord[i%2].end(), i));
        lastmatch = max(lastmatch, ((1+m%2)*m-i+pos)/2);
      }
    }
  } else lastmatch = -1;

  cout << tot << " " << lastmatch;
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");


int main() {
  int n, m; cin >> n >> m;

  vector<int> fat(n, -1);
  vector<array<int, 3>> e;
  vector<long long> dist(n, 0);
  for(int i = 0; i < m; i++){
    int a, b, c; cin >> a >> b >> c;
    e.push_back({--a, --b, c});
  }

  int mod;
  for(int i = 0; i < n; i++){
    mod = -1;
    for(auto [a, b, c] : e){
      if(dist[b] > dist[a]+c){
        fat[b] = a; mod = b;
        dist[b] = dist[a]+c;
      }
    }
  }

  if(mod == -1) cout << "NO";
  else{
    cout << "YES" << '\n';

    for(int i = 0; i < n; i++, mod = fat[mod]);

    int start = mod;
    vector<int> ans;
    do{
      ans.push_back(mod+1);
      mod = fat[mod];
    }while(mod != start);
    
    cout << mod+1 << " ";
    for(int i = ans.size()-1; i >= 0; i--) cout << ans[i] << " ";
  }
}
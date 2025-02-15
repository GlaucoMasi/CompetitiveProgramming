#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
ifstream fin("input.txt");
ofstream fout("output.txt");
//fout << "Case #" << t << ": ";

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  int n, m, q; cin >> n >> m >> q;
  int pizzas = 1<<n;

  vector<long long> add(n), rem(n);
  for(int i = 0; i < n; i++) cin >> add[i] >> rem[i];

  vector<bool> prop(pizzas);
  vector<long long> dist(pizzas, 2e18);
  priority_queue<pair<long long, int>> pq;

  for(int i = 0; i < m; i++){
    int k; cin >> k;
    int curr = 0;
    while(k--){
      int a; cin >> a;
      curr += (1<<a);
    }

    dist[curr] = 0;
    pq.push({0, curr});
  }

  while(!pq.empty()){
    int i = pq.top().second; pq.pop();

    if(prop[i]) continue;
    prop[i] = 1;

    for(int j = 0; j < n; j++){
      int next = i^(1<<j);
      if(i&(1<<j)){
        if(dist[next] > dist[i]+rem[j]){
          dist[next] = dist[i]+rem[j];
          pq.push({-dist[next], next});
        }
      }else{
        if(dist[next] > dist[i]+add[j]){
          dist[next] = dist[i]+add[j];
          pq.push({-dist[next], next});
        }        
      }
    }
  }

  while(q--){
    int k; cin >> k;
    int curr = 0;
    while(k--){
      int a; cin >> a;
      curr += (1<<a);
    }

    cout << dist[curr] << '\n';
  }
}
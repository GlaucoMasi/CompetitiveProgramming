#include <bits/stdc++.h>
using namespace std;

int visita(int n, int m, int k, vector<int> s, vector<int> a, vector<int> b, vector<int> t){
  vector<vector<pair<int, int>>> g(n);
  for(int i = 0; i < m; i++){
    g[a[i]].push_back({b[i], t[i]});
    g[b[i]].push_back({a[i], t[i]});
  }

  vector<bool> prop(n);
  vector<int> dist(n, -1); dist[0] = k;
  priority_queue<pair<int, int>> pq; pq.push({k, 0});
  while(!pq.empty()){
    int i = pq.top().second; pq.pop();

    if(prop[i]) continue;
    prop[i] = 1;

    for(auto [j, c] : g[i]){
      if(dist[j] < min(dist[i], c)){
        dist[j] = min(dist[i], c);
        pq.push({dist[j], j});
      }
    }
  }

  int ans = 0;
  vector<int> count(k+1);
  for(auto i : s) count[dist[i]]++;

  int cum = count[k];
  for(int i = k-1; i >= 0; i--){
    if(cum){
      ans++;
      cum--;
    }

    cum += count[i];
  }

  return ans;
}

int main() {
    int N, M, K; cin >> N >> M >> K;
    vector<int> S(K), A(M), B(M), T(M);

    for(int i=0; i<K; i++){
        cin >> S[i];
    }

    for(int i=0; i<M; i++){
        cin >> A[i] >> B[i] >> T[i];
    }

    cout << visita(N, M, K, S, A, B, T) << "\n";
}

#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

const int INF = 2e9;

int main(){ 

  fin.tie(0);
  fin.sync_with_stdio(0);

  int N, M;

  fin >> N >> M;

  int ans = INF;

  vector<vector<pair<int, int>>> g(N);

  for(int i = 0; i < M; i++){
    int a, b, c;

    fin >> a >> b >> c;

    a--;
    b--;

    g[b].push_back({a, c});
    g[a].push_back({b, c});
  }

  for(int a = 0; a < N; a++){
    for(auto e : g[a]){
      int b = e.first;

      if(b < a)
      continue;

      queue<int> q;
      vector<int> dist(N, INF);
      dist[a] = 0;
      q.push(a);

      while(!q.empty()){
        int curr = q.front();
        q.pop();

        if(dist[curr] + e.second > ans)
        continue;

        for(auto arco : g[curr]){
          int next = arco.first;
          
          if((curr == a && next == b) || (curr == b && next == a))
            continue;
  
          if(dist[curr] + arco.second < dist[next]){
            dist[next] = dist[curr] + arco.second;
            q.push(next);
          }
        }
      }

      int ciclo = e.second + dist[b];
      ans = min(ciclo, ans);

    }
  }

  fout << ans;

}
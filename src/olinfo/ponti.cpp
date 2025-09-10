#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {

  fin.tie(0);
  fin.sync_with_stdio(0);

  int N, M;
  int visite = 0;

  fin >> N >> M;

  vector<vector<int>> isole(N);

  for(int i = 0; i < M; i++){

    int a, b;

    fin >> a >> b;

    isole[a].push_back(b);
    isole[b].push_back(a);
  }

  vector<bool> vis(N);

  for(int i = 0; i < N; i++){

    if(!vis[i]){
      visite++;
      queue<int> q;
      q.push(i);
      vis[i] = 1;
      
      while(!q.empty()){
        int current = q.front();
        q.pop();

        for(auto vic : isole[current]){
          if(!vis[vic]){
            q.push(vic);
            vis[vic] = 1;
          }
        }
      }
    }
  }
  
  fout << visite - 1;

}
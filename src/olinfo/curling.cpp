#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n;
  vector<vector<bool>> v;
  
  fin >> n;
  v.resize(n, vector<bool>(n, 0));

  for(int i = 0; i < n*(n-1)/2; i++){
    int a, b;
    fin >> a >> b;

    v[a-1][b-1] = 1;
  }

  deque<int> path;
  path.push_back(0);

  for(int i = 1; i < n; i++){
    bool found = 0;

    for(int j = path.size()-1; j >= 0; j--){
      if(v[path[j]][i]){
        found = 1;
        path.insert(path.begin() + j+1, i);
        break;
      }
    }

    if(!found) path.insert(path.begin(), i);
  }
  
  fout << n-1 << endl << path[0]+1 << " ";
  for(int i = 1; i < n-1; i++) fout << path[i]+1 << endl << path[i]+1 << " ";
  fout << path[n-1]+1;
}
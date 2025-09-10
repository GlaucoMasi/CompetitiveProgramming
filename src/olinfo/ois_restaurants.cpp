#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;
  priority_queue<pair<int, int>, vector<pair<int, int>>> pq;

  for(int i = 0; i < n; i++){
    int a, tot = 0;

    for(int j = 0; j <= n; j++){
      fin >> a;
      if(a == -1) continue;
      else tot += a;
    }

    pq.push({tot, i+1});
    fout << pq.top().second << endl;
  }
}
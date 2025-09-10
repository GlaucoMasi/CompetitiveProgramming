#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; cin >> n;
  queue<int> q;
  for(int i = 1; i <= n; i++) q.push(i);

  while(!q.empty()){
    q.push(q.front()); q.pop();
    cout << q.front() << " ";
    q.pop();
  }
}
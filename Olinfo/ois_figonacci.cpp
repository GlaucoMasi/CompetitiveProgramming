#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, m; fin >> n >> m;

  long long sum = -1, last = 0;
  for(int i = 2; i <= n; i++){
    long long curr = (((last*(i-1))%m-sum)%m+m)%m;
    sum += last;
    last = curr;
  }

  fout << last;
}
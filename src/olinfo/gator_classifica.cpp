#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;
  vector<int> v(n);

  int tot = 0;
  for(int i = n-1; i > 0; i--) tot += i;

  int a, b, c, d;
  for(int i = 0; i < tot; i++){
    fin >> a >> b >> c >> d;

    if(c > d) v[a-1] += 3;
    else if(d > c) v[b-1] += 3;
    else{
      v[a-1] += 1;
      v[b-1] += 1;
    }
  }

  auto ans = max_element(v.begin(), v.end()) - v.begin();
  fout << ans+1 << " " << v[ans];
}
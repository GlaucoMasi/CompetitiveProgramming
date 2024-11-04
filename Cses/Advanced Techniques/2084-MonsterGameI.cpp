#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

struct line{
  long long m, q;
  long long eval(long long x){ return m*x+q; }
};

bool bad(line a, line b, line n){ return (a.q-b.q)*(a.m-n.m) <= (n.q-a.q)*(b.m-a.m); }

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n, x; cin >> n >> x;
  vector<long long> s(n), f(n);
  for(auto &i : s) cin >> i;
  for(auto &i : f) cin >> i;

  deque<line> dq; dq.push_back({x, 0});
  for(int i = 0; i < n; i++){
    while(dq.size() >= 2 && dq[0].eval(s[i]) >= dq[1].eval(s[i])) dq.pop_front();

    long long ans = dq[0].eval(s[i]);
    if(i == n-1) cout << ans;

    line curr = {f[i], ans};
    while(dq.size() >= 2 && bad(dq[dq.size()-2], dq[dq.size()-1], curr)) dq.pop_back();
    dq.push_back(curr);
  }
}
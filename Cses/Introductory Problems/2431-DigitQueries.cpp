#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int q; cin >> q;
  vector<pair<long long, int>> v(q);
  for(int i = 0; i < q; i++) cin >> v[i].first, v[i].second = i;
  sort(v.begin(), v.end());

  vector<char> ord(q);
  long long nums = 0, pos = 0, dig = 1, add = 9;
  for(auto [i, idx] : v){
    while(pos + dig*add < i) pos += dig*add, nums += add, dig++, add *= 10LL;

    long long dist = i-pos;
    long long num = nums + (dist+dig-1)/dig;
    string ans = to_string(num);

    ord[idx] = (dist%dig ? ans[dist%dig-1] : ans.back());
  }

  for(auto i : ord) cout << i << '\n';
}
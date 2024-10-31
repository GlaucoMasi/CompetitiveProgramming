#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

template<typename k>
using ordered_set = tree<k, null_type, less<k>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  int n, k; cin >> n >> k;
  ordered_set<int> s;
  for(int i = 1; i <= n; i++) s.insert(i);

  int idx = 0;
  for(int i = 0; i < n; i++){
    idx += k; idx %= s.size();
    cout << *s.find_by_order(idx) << " ";
    s.erase(s.find_by_order(idx));
  }
}
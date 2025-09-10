#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

template<typename k>
using ordmultiset = tree<k, null_type, less_equal<k>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  int n, k; cin >> n >> k;
  vector<int> v(n); for(auto &i : v) cin >> i;

  ordmultiset<int> s;
  for(int i = 0; i < n; i++){
    s.insert(v[i]);
    if(i > k-1) s.erase(s.find_by_order(s.order_of_key(v[i-k])));

    if(i >= k-1) cout << *s.find_by_order((k-1)/2) << " ";
  }
}
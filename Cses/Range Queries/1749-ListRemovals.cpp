#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

template<typename K, typename V>
using ordered_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  int n; cin >> n;
  ordered_map<int, int> map;

  for(int i = 0; i < n; i++){
    int a; cin >> a;
    map[i] = a;
  }

  for(int i = 0; i < n; i++){
    int a; cin >> a; a--;

    cout << map.find_by_order(a)->second << " ";
    map.erase(map.find_by_order(a));
  }
}

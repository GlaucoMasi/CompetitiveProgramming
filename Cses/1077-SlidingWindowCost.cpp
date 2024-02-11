#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

template<typename k>
using ordmultiset = tree<k, null_type, less_equal<k>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
  int n, k; cin >> n >> k;
  vector<int> v(n); for(auto &i : v) cin >> i;

  long long sums = 0, sumb = 0;
  ordmultiset<long long> small, big;
  for(int i = 0; i < n; i++){
    if(small.empty() || *prev(small.end()) >= v[i]){
      small.insert(v[i]);
      sums += v[i];
    }else{
      big.insert(v[i]);
      sumb += v[i];      
    }

    if(i-k >= 0){
      if(!big.empty() && *big.begin() <= v[i-k]){
        big.erase(big.find_by_order(big.order_of_key(v[i-k])));
        sumb -= v[i-k];
      }else{
        small.erase(small.find_by_order(small.order_of_key(v[i-k])));
        sums -= v[i-k];        
      }
    }

    while(small.size() > (k+1)/2){
      sumb += *prev(small.end()); sums -= *prev(small.end());
      big.insert(*prev(small.end()));
      small.erase(prev(small.end()));
    }

    while(big.size() > k/2){
      sums += *big.begin(); sumb -= *big.begin();
      small.insert(*big.begin());
      big.erase(big.begin());      
    }

    if(i >= k-1) cout << sumb-sums + *prev(small.end())*(k%2) << " ";
  }
}
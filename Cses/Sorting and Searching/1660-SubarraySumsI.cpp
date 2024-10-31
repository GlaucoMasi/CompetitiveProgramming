#include <iostream>
#include <vector>
 
using namespace std;
 
int main() {
  int n, x;
  cin >> n >> x;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
 
  int left = 0;  // extreme included
  int right = 0; // extreme included
  long long sum = a[0];
  int res = 0;
  while (left < n) {
    // advance the right pointer
    while (sum < x && right < n) {
      right++;
      sum += a[right];
    }
    if (sum == x) {
      // cerr << "found at [" << left << ", " << right << "]" << endl;
      res++;
    }
    // advance the left pointer
    sum -= a[left];
    left++;
  }
  cout << res << endl;
}
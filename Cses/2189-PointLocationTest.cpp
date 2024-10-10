#include <bits/stdc++.h>
using namespace std;

struct point{
  long long x, y;
};

int main() {
  int t; cin >> t;

  for(int i = 0; i < t; i++){
    point p, q, a;
    cin >> p.x >> p.y >> q.x >> q.y >> a.x >> a.y;

    point pa, pq;
    pa.x = a.x - p.x;
    pa.y = a.y - p.y;

    pq.x = q.x - p.x;
    pq.y = q.y - p.y;

    long long ans = pq.x*pa.y - pa.x*pq.y;
    if(ans > 0) cout << "LEFT" << endl;
    else if(ans < 0) cout << "RIGHT" << endl;
    else cout << "TOUCH" << endl;
  }
}
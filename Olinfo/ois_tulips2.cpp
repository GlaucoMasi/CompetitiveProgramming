#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout << (#x) << " is " << (x) << endl
ifstream fin("input.txt");
ofstream fout("output.txt");
//fout << "Case #" << t << ": ";

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  
  long long x, y, X, Y;
  cin >> x >> y >> X >> y >> X >> Y >> x >> Y;

  long long dista = (X-x)*(X-x), distb = (Y-y)*(Y-y);

  int n, ans = 0; cin >> n;
  while(n--){
    long long a, b; cin >> a >> b;
    long long dist1 = abs(a-x)*abs(a-x) + abs(b-y)*abs(b-y);
    long long dist2 = abs(a-X)*abs(a-X) + abs(b-y)*abs(b-y);
    long long dist3 = abs(a-X)*abs(a-X) + abs(b-Y)*abs(b-Y);
    long long dist4 = abs(a-x)*abs(a-x) + abs(b-Y)*abs(b-Y);

    if(dist1+dist2 == dista) continue;
    if(dist2+dist3 == distb) continue;
    if(dist3+dist4 == dista) continue;
    if(dist4+dist1 == distb) continue;
    
    int tot = 0;
    if(dist1+dist2 > dista) tot++;
    else tot--;
    if(dist2+dist3 > distb) tot++;
    else tot--;
    if(dist3+dist4 > dista) tot++;
    else tot--;
      if(dist4+dist1 > distb) tot++;
    else tot--;

    ans += !tot;
  }

  cout << ans;
}
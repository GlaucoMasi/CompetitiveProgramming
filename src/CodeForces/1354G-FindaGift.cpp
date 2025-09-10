#include <bits/stdc++.h>
using namespace std;

int main() {
  int tt; cin >> tt;
  while(tt--){
    int n, k; cin >> n >> k;
    string ans;

    int numquer = 30;

    bool isstone = 1;
    for(int i = 0; i < numquer && isstone; i++){
      int next = rand()%n+1;

      if(next == 1){
        i--;
        continue;
      }

      cout << "? 1 1\n" << 1 << '\n' << next << endl;
      cin >> ans;
      if(ans == "SECOND") isstone = 0;
    }

    if(!isstone){
      cout << "! " << 1 << endl;
      continue;
    }

    int lim = 1;
    while(2*lim <= n){
      cout << "? " << lim << " " << lim << '\n';
      for(int i = 1; i <= lim; i++) cout << i << " "; cout << '\n';
      for(int i = lim+1; i <= 2*lim; i++) cout << i << " "; cout << endl;
      cin >> ans;

      if(ans != "EQUAL") break;
      else lim *= 2;
    }

    int l = lim+1, r = min(lim*2+1, n+1);
    while(l < r-1){
      int m = (l+r)/2-1;

      int size = m-lim;
      cout << "? " << size << " " << size << '\n';
      for(int i = 1; i <= size; i++) cout << i << " "; cout << '\n';
      for(int i = lim+1; i <= lim+size; i++) cout << i << " "; cout << endl;
      cin >> ans;

      if(ans == "EQUAL") l = m+1;
      else r = m+1;
    }

    cout << "! " << l << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;

bool solve() {
  int a, b; cin >> a >> b;
  if(a < 33) return 0;

  if(a == 33 && b <= 30){
    for(int i = 0; i < 3; i++){
      cout << 11 << " " << min(b, 10) << '\n';
      b -= min(b, 10);
    }
  }else if(a <= 43 && b >= 11 && b <= 41){
    cout << a-33 << " " << 11 << '\n';
    b -= 11;

    for(int i = 0; i < 3; i++){
      cout << 11 << " " << min(b, 10) << '\n';
      b -= min(b, 10);
    }
  }else if(a <= 53 && b >= 22 && b <= 52){
    cout << min(10, a-33) << " " << 11 << '\n';
    a -= min(10, a-33);
    cout << a-33 << " " << 11 << '\n';
    
    b -= 22;
    for(int i = 0; i < 3; i++){
      cout << 11 << " " << min(b, 10) << '\n';
      b -= min(b, 10);
    }
  }else return 0;

  return 1;
}

int main() {
  int t; cin >> t;
  while(t--) if(!solve()) cout << "-1 -1\n";
}
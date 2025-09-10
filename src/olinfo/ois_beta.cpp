#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n;
    vector<bool> v(1e9+5, 0);
    
    bool found = 0;
    int pass;
    string ans = "NO";
    
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        
        if(v[a] && !found){
          found = 1;
          pass = a;
        }else if(v[a] && found && pass != a){
            ans = "YES";
            break;
        }else if(!v[a]) v[a] = 1;
    }
    
    cout << ans;
}
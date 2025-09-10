#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, t; cin >> n >> t;
    int first = -1;
    
    int a, b; cin >> a;
    
    for(int i = 0; i < n-1; i++){
        cin >> b >> a;
        
        if(24-b+a >= t){
            first = i;
            break;
        }
    }
    
    cout << first;
}
#include <bits/stdc++.h>
using namespace std;

int n, mod, fact;
const int N = 1000001;
int dp[N], inv[N];

int binexp(int b, int e){
    int ans = 1;

    for(int j = 0; j < 32; j++){
        if(e & (1<<j)) ans = 1LL*ans*b%mod;
        b = 1LL*b*b%mod;
    }

    return ans;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n >> mod;
    fact = dp[0] = 1;
    for(int i = 1; i <= n; i++) dp[i] = 1LL*dp[i-1]*(2*i-1)%mod;
    for(int i = 1; i <= n; i++) fact = 1LL*fact*i%mod;

    inv[n] = binexp(fact, mod-2);
    for(int i = n-1; i >= 0; i--) inv[i] = 1LL*inv[i+1]*(i+1)%mod;

    for(int i = 0; i <= n; i++){
        int ways = 1LL*dp[i]*dp[n-i]%mod, molt = 1LL*fact*inv[i]%mod*inv[n-i]%mod;
        cout << 1LL*ways*molt%mod << " ";
    }
}
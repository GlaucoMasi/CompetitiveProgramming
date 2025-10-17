#include <bits/stdc++.h>
using namespace std;
const int N = 300;
const int mod = 1e9+7;
int dp[2][N+1][N+1];
void solve() {
    int n; cin >> n;
    for(int m1 = 0; m1 <= n; m1++){
        for(int m2 = 0; m2 <= n; m2++){
            dp[0][m1][m2] = 0;
            dp[1][m1][m2] = 0;
        }
    }
    dp[0][0][0] = 1;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        for(int m1 = 0; m1 <= n; m1++){
            for(int m2 = 0; m2 <= n; m2++){
                dp[1][m1][m2] = (dp[1][m1][m2]+dp[0][m1][m2])%mod;
                if(m1 <= a) dp[1][a][m2] = (dp[1][a][m2]+dp[0][m1][m2])%mod;
                else if(m1 > a && m2 <= a) dp[1][m1][a] = (dp[1][m1][a]+dp[0][m1][m2])%mod;
            }
        }
        for(int m1 = 0; m1 <= n; m1++){
            for(int m2 = 0; m2 <= n; m2++){
                dp[0][m1][m2] = dp[1][m1][m2];
                dp[1][m1][m2] = 0;
            }
        }
    }
    int ans = 0;
    for(int i = 0; i <= n; i++) for(int j = 0; j <= n; j++) ans = (ans+dp[0][i][j])%mod;
    cout << ans << '\n';
}
int main() {
    int t; cin >> t;
    while(t--) solve();
}
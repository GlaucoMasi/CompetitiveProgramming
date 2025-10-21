#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; fin >> n;
    vector<int> v(n); for(auto &i : v) fin >> i;

    int mod = 1e9+7;
    vector<int> dp(n); dp[0] = 1;
    for(int i = 0; i < n; i++){
        for(int j = 0; (1<<j) <= i; j++) if((v[i] + v[i-(1<<j)])%(1<<j) == 0) dp[i] = (dp[i]+dp[i-(1<<j)])%mod;
    }

    fout << dp[n-1];
}
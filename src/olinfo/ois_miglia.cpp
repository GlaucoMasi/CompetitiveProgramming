#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    int k, n, m; fin >> k >> n >> m;
    
    vector<array<int, 3>> e;
    for(int i = 0; i < m; i++){
        int a, b, c; fin >> a >> b >> c;
        e.push_back({a, b, c});
    }

    vector<int> dp(n, -1e9); dp[0] = 0;
    while(k--){
        vector<int> next(n, -1e9);
        for(auto [a, b, c] : e) next[b] = max(next[b], dp[a]+c);
        swap(next, dp);
    }

    fout << dp[0];
}
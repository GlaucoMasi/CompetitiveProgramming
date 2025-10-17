#include <bits/stdc++.h>
using namespace std;

int dividi(int n, vector<int> v) {
    int tot = 0;
    constexpr int maxsum = 100000;
    bitset<maxsum> dp; dp.set(0);
    for(auto i : v) {
        dp = dp | (dp << i);
        tot += i;
    }
    int best = 1e9;
    for(int i = 0; i <= maxsum; i++)
        if(dp[i]) best = min(best, abs(2*i-tot));
    return best;
}


#ifndef EVAL

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int N; cin >> N;

    vector<int> V(N);
    for(auto &x: V) cin >> x;

    cout << dividi(N, V) << endl;
}

#endif
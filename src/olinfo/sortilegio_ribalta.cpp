#include <bits/stdc++.h>
using namespace std;

int ribalta(int n, string s) {
    int start = 0, curr = 0, best = 0;
    for(auto c : s) {
        start += (c == '1');
        curr += (c == '1' ? -1 : 1);
        best = max(best, curr);
    }
    return start+best;
}


#ifndef EVAL

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N; cin >> N;

    string S; cin >> S;

    cout << ribalta(N, S) << endl;
}

#endif
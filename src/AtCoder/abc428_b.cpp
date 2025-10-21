#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;
    string s;
    cin >> n >> k >> s;

    int best = 0;
    vector<string> ans;
    unordered_map<string, int> freq;
    for(int i = 0; i+k <= n; i++){
        string curr = s.substr(i, k);
        freq[curr]++;

        if(freq[curr] > best){
            best = freq[curr];
            ans.clear();
        }

        if(freq[curr] == best){
            ans.push_back(curr);
        }
    }

    cout << best << '\n';
    sort(ans.begin(), ans.end());
    for(auto i : ans) cout << i << " ";
}
#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    int n; fin >> n;
    int ans = 0;
    vector<int> v(n);
    for(int i = 0; i < n; i++) fin >> v[i];
    vector<int> memo(n);

    for(int i = 0; i < n; i++){
        int best = 1;

        for(int j = i-1; j >= 0; j--){
            if(v[j] > v[i]) best = max(best, memo[j]+1);
        }

        memo[i] = best;
    }

    fout << *max_element(memo.begin(), memo.end());
}
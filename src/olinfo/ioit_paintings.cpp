#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    int h, n; fin >> h >> n;
    vector<pair<int, int>> v(n); for(auto &[a, b] : v) fin >> a >> b;

    int ans = 0, i = 0, j = n-1;
    while(i < j){
        if(v[i].first < h || v[i].second < h) i++;
        else if(v[j].first > h || v[j].second > h) j--;
        else ans++, i++, j--;
    }

    fout << ans;
}
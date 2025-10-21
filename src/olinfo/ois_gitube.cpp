#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    int d, n; fin >> d >> n;
    vector<int> v(d);

    while(n--){
        int a; fin >> a;
        v[--a]++;
    }

    vector<vector<char>> ans;
    for(int i = 0; i < d; i += 7){
        int days = min(7, d-i);
        vector<char> temp(days);
        for(int j = 0; j < days; j++){
            if(v[i+j] < 10) temp[j] = '.';
            else if(v[i+j] < 20) temp[j] = 'o';
            else temp[j] = 'O';
        }
        ans.push_back(temp);
    }

    for(int j = 0; j < 7; j++){
        for(int i = 0; i < ans.size() && ans[i].size() > j; i++) fout << ans[i][j];
        fout << '\n';
    }
}
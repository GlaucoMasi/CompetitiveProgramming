#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    int n; fin >> n;

    int minimo = 1e9;
    vector<int> add(n);
    for(int i = 0; i < n; i++){
        int c; fin >> c;
        add[i] = c-10;
        if(i != 0) add[i] += add[i-1];
        minimo = min(minimo, add[i]);
    }

    for(int i = 0; i < n; i++) if(minimo >= (i == 0 ? add[n-1] : add[i-1])){
        fout << i+1;
        break;
    }
}
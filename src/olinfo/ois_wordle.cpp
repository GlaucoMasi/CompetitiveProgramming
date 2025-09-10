#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
    int n, tot = 26, sp = 0;
    fin >> n;
    
    char c;    
    for(int i = 0; i < n; i++){
        fin >> c;
        if(c == '_') sp++;
    }
    
    tot -= (n - sp);
    
    long long ans = 1;
    while(sp--){
        ans *= tot;
        tot--;
    }
    
    fout << ans;
}
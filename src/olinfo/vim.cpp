#include <bits/stdc++.h>
using namespace std;

void valuta(int n, int c[], int l[], int p[]){    
    vector<int> add(n); add[0] = c[0]-l[0];
    
    int minimo = add[0];
    for(int i = 1; i < n; i++) minimo = min(minimo, add[i] = add[i-1] + c[i]-l[i]);
    for(int i = 0; i < n; i++) p[i] = (minimo >= (i == 0 ? add[n-1] : add[i-1]));
}
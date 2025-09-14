#include <bits/stdc++.h>
using namespace std;

int direziona(int n, vector<int> a, vector<int> b){
    int left = 0, right = n-1;
    for(int i = 0; i < n; i++) if(a[i] > b[left]) left++;
    for(int i = n-1; i >= 0; i--) if(a[i] < b[right]) right--;
    return left - right;
}
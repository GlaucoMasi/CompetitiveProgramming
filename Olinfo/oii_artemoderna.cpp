#include <bits/stdc++.h>
using namespace std;

bool ordina(int n, vector<int> v, vector<int> &l){
  int i = 0;

  while(i < n){
    int j = i;
    while(j+1 < n && v[j+1] <= v[j]) j++;

    if(i && v[j] < v[i-1]) return 0;

    l.push_back(j-i+1);
    swap(v[i], v[j]);
    i = j+1;
  }

  return 1;
}
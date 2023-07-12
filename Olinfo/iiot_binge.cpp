#include <bits/stdc++.h>
using namespace std;

int main() {
  int m, n;
  cin >> m >> n;

  long long days = 1; int left = m;
  for(int i = 0; i < n; i++){
    int num, l;
    cin >> num >> l;

    int today = left/l;

    if(today >= num) left -= num*l;
    else{
      num -= today;
      days++;

      int inaday = m/l;
      days += num/inaday-1;
      left = m - inaday*l;

      if(num%inaday){
        days++;
        left = m - (num%inaday)*l;
      }
    }
  }

  cout << days << " " << left;
}
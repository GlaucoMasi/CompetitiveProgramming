#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  string a; int ans = 0, idx = 1;

  while(getline(fin, a)){
    bool ok = 1;

    int i = 8+log10(idx);
    while(i < a.size()){
      int num = a[i]-'0';
      while((a[i+1]-'0') >= 0 && (a[i+1]-'0') <= 9){
        num *= 10;
        num += a[i+1]-'0';
        i++;
      }
      char col = a[i+2];

      if(col == 'b'){
        if(num > 14) ok = 0;
        i += 8;
      }else if(col == 'r'){
        if(num > 12) ok = 0;
        i += 7;
      }else{
        if(num > 13) ok = 0;
        i += 9;
      }
    }

    if(ok) ans += idx;
    idx++;
  }

  fout << ans;
}
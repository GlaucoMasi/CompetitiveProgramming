#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  string a;
  long long ans = 0;
  int idx = 1;

  while(getline(fin, a)){
    int red = 0, blue = 0, green = 0;

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
        blue = max(blue, num);
        i += 8;
      }else if(col == 'r'){
        red = max(red, num);
        i += 7;
      }else{
        green = max(green, num);
        i += 9;
      }
    }

    ans += red*blue*green;
    idx++;
  }

  fout << ans;
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  string a; int ans = 0;
  while(fin >> a){
    for(int i = 0; i < a.size(); i++){
      int c = a[i]-'0';
      if(c >= 0 && c <= 9){
        ans += 10*c;
        break;
      }
    }

    for(int i = a.size()-1; i >= 0; i--){
      int c = a[i]-'0';
      if(c >= 0 && c <= 9){
        ans += c;
        break;
      }
    }
  }

  fout << ans;
}
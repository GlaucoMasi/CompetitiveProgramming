#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int n;
string v = "", per = "";

bool check() {
  int tot = per.size();
  if(!tot) return false;
  if(v.size() % tot != 0) return 0;

  int j = 0;
  for(int i = 0; i < n; i++){
    if(j == tot) j = 0;
    if(v[i] != per[j]) return 0;
    j++;
  }

  return 1;
}

int main() {
  fin >> n;
  
  for(int i = 0; i < n; i++){
    char a; fin >> a; v += a;
  }

  string ans = "2";
  for(int i = 0; i < n; i++){
    if(check()){
      for(auto i : per) fout << i << " ";
      ans = "";
      break;
    }else per += v[i];
  }

  fout << ans;
}
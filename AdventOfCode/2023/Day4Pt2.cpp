#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  string a; int ans = 0;
  int start = -1, bar = -1;

  int idx = 0;
  vector<int> cop(300, 1);

  while(getline(fin, a)){
    if(bar == -1) for(int i = 0; i < a.size(); i++) if(a[i] == '|') bar = i;
    if(start == -1) for(int i = a.size()-1; i >= 0; i--){
      if(a[i] == ':') break;
      if((a[i]-'0') >= 0 && (a[i]-'0') <= 9) start = i;
    }

    vector<bool> v(100);

    int j = start;
    for(j; j < bar; j += 3) v[(a[j+1]-'0') + 10*(a[j] != 32)*(a[j]-'0')] = 1;

    int count = 0;
    j = bar+2;
    for(j; j < a.size(); j += 3) count += v[(a[j+1]-'0') + 10*(a[j] != 32)*(a[j]-'0')];

    for(int i = idx+1; i <= idx+count; i++) cop[i] += cop[idx];

    ans += cop[idx]; idx++;
  }

  fout << ans;
}
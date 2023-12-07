#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  vector<array<int, 7>> v;

  string a;
  while(fin >> a){
    array<int, 7> temp; fin >> temp[6];

    for(int i = 0; i < 5; i++){
      int t = a[i]-'0';

      if(t >= 0 && t <= 9) temp[i+1] = t;
      else if(a[i] == 'T') temp[i+1] = 10;
      else if(a[i] == 'J') temp[i+1] = 11;
      else if(a[i] == 'Q') temp[i+1] = 12;
      else if(a[i] == 'K') temp[i+1] = 13;
      else temp[i+1] = 14;
    }

    vector<int> cnt(15);
    for(int i = 1; i <= 5; i++) cnt[temp[i]]++;

    int tot = 0;
    for(auto i : cnt) if(i == 2) tot++;
    int high = max_element(cnt.begin(), cnt.end()) - cnt.begin();

    if(cnt[high] == 1) temp[0] = 1;
    else if(cnt[high] == 2){
      if(tot == 1) temp[0] = 2;
      else temp[0] = 3;
    }else if(cnt[high] == 3){
      if(tot == 0) temp[0] = 4;
      else temp[0] = 5;
    }else if(cnt[high] == 4) temp[0] = 6;
    else temp[0] = 7;

    v.push_back(temp);
  }


  int ans = 0;
  sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); i++) ans += (i+1)*v[i][6];
  fout << ans;
}
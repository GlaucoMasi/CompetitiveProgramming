#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<vector<array<long long, 3>>> v;

long long conv(string t){
  long long ans = 0;
  for(auto c : t) ans = 10*ans+(c-'0');
  return ans;
}

int main() {
  vector<long long> seeds;
  string a; fin >> a;
  
  while(fin >> a){
    if(a == "seed-to-soil"){
      fin >> a;
      break;
    }

    seeds.push_back(conv(a));
  }

  for(int i = 0; i < 7; i++){
    vector<array<long long, 3>> t;

    while(fin >> a){
      if((a[0]-'0') < 0 || (a[0]-'0') > 9){
        fin >> a;
        break;
      }

      string b, c; fin >> b >> c;
      t.push_back({conv(b), conv(a), conv(c)});
    }

    sort(t.begin(), t.end());
    v.push_back(t);
  }

  long long ans = 1e18;
  for(auto i : seeds){
    for(auto t : v){
      array<long long, 3> s = {i, 0, 0};
      int idx = upper_bound(t.begin(), t.end(), s)-t.begin();
      if(!idx) continue;
      idx--;
      if(t[idx][0]+t[idx][2] < i) continue;
      i = t[idx][1] + i - t[idx][0]; 
    }

    ans = min(ans, i);
  }

  fout << ans;
}
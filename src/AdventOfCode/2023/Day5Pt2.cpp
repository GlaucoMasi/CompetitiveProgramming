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
  queue<pair<long long, long long>> seeds;
  string a; fin >> a;
  
  while(fin >> a){
    if(a == "seed-to-soil"){
      fin >> a;
      break;
    }

    string b; fin >> b;

    seeds.push({conv(a), conv(b)});
  }

  for(int i = 0; i < 7; i++){
    vector<array<long long, 3>> t;
    long long small = 1e18, big = -1e18;

    while(fin >> a){
      if((a[0]-'0') < 0 || (a[0]-'0') > 9){
        fin >> a;
        break;
      }

      string b, c; fin >> b >> c;
      small = min(small, conv(b)); big = max(big, conv(b)+conv(c));
      t.push_back({conv(b), conv(a), conv(c)});
    }

    t.push_back({0, 0, small});
    t.push_back({big, big, 1000000000000000});
    sort(t.begin(), t.end());

    int s = t.size();
    for(int i = 0; i < s; i++) if(i != s-1 && t[i][0] + t[i][2] != t[i+1][0]) t.push_back({t[i][0]+t[i][2], t[i][0]+t[i][2], t[i+1][0]-t[i][0]-t[i][2]});
    sort(t.begin(), t.end());
    v.push_back(t);
  }

  long long ans = 1e18;
  for(auto t : v){
    queue<pair<long long, long long>> next;

    while(!seeds.empty()){
      auto [i, l] = seeds.front(); seeds.pop();
      
      int idx = 0, r = t.size();
      while(idx < r-1){
        int m = (idx+r)/2;

        if(t[m][0] > i) r = m;
        else idx = m;
      }

      if(i+l > t[idx][0]+t[idx][2]){
        next.push({t[idx][1] + i - t[idx][0], t[idx][0]+t[idx][2]-i});
        seeds.push({t[idx][0]+t[idx][2], l-(t[idx][0]+t[idx][2]-i)});
      }else next.push({t[idx][1] + i - t[idx][0], l});
    }

    seeds = next;
  }

  while(!seeds.empty()){
    ans = min(ans, seeds.front().first);
    seeds.pop();
  }

  fout << ans;
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; cin >> n;
  vector<int> v(n); for(auto &i : v) cin >> i;

  vector<vector<pair<int, int>>> fact(n);
  for(int i = 0; i < n; i++){
    for(int j = 2; j <= 1e3; j++){
      int freq = 0;
      while(!(v[i]%j)) v[i] /= j, freq++;
      if(freq%4) fact[i].push_back({j, freq%4});
    }
    
    if(v[i] != 1) fact[i].push_back({v[i], 1});
  }

  auto merge = [&](int i, int j){
    long long curr = 1, need = 1;
    vector<pair<int, int>> a = fact[i], b = fact[j];
    int idxa = 0, idxb = 0;

    while(idxa < a.size() || idxb < b.size()){
      if(idxb != b.size() && (idxa == a.size() || b[idxb].first < a[idxa].first)){
        for(int k = 0; k < 4-b[idxb].second; k++) need *= (long long)b[idxb].first;
        for(int k = 0; k < b[idxb].second; k++) curr *= (long long)b[idxb].first;
        idxb++;
      }else if(idxa != a.size() && (idxb == b.size() || a[idxa].first < b[idxb].first)){
        for(int k = 0; k < 4-a[idxa].second; k++) need *= (long long)a[idxa].first;
        for(int k = 0; k < a[idxa].second; k++) curr *= (long long)a[idxa].first;
        idxa++;
      }else{
        int tot = b[idxb].second+a[idxa].second; tot %= 4;
        if(tot) for(int k = 0; k < 4-tot; k++) need *= (long long)a[idxa].first;
        for(int k = 0; k < tot; k++) curr *= (long long)a[idxa].first;
        idxa++; idxb++;
      }
    }

    return make_pair(curr, need);
  };

  long long ans = 0;
  unordered_map<long long, int> freq;
  for(int i = 0; i < n; i++){
    for(int j = n-1; j >= 0; j--){
      auto [curr, need] = merge(i, j);
      if(j < i) freq[curr]++;
      else if(j > i) ans += freq[need];
    }
  }

  cout << ans;
}
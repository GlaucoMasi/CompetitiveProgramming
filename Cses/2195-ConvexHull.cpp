#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>> v, ans;

void calc() {
  vector<pair<int, int>> temp;
  temp.push_back(v[0]); temp.push_back(v[1]);

  for(int i = 2; i < n; i++){
    while(temp.size() >= 2){
      pair<long long, long long> v1 = {temp[temp.size()-1].first-temp[temp.size()-2].first, temp[temp.size()-1].second-temp[temp.size()-2].second};
      pair<long long, long long> v2 = {v[i].first-temp[temp.size()-2].first, v[i].second-temp[temp.size()-2].second};

      long long pv = v1.second*v2.first-v1.first*v2.second;
      if(pv < 0) temp.pop_back();
      else break;
    }

    temp.push_back(v[i]);
  }

  for(auto i : temp) if(i != v[0] && i != v.back()) ans.push_back(i);
}

int main() {
  cin >> n;
  v.resize(n);
  for(auto &i : v) cin >> i.first >> i.second;

  sort(v.begin(), v.end());
  ans.push_back(v[0]); ans.push_back(v.back());
  
  calc();
  reverse(v.begin(), v.end());
  calc();

  cout << ans.size() << endl;
  for(auto i : ans) cout << i.first << " " << i.second << endl;
}
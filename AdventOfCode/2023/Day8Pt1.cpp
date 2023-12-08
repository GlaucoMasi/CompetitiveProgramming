#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  string inst; fin >> inst;
  string a;

  vector<pair<int, int>> v;
  map<string, int> m;
  int idx = 0;

  while(getline(fin, a)){
    if(a.empty()) continue;
    string start = a.substr(0, 3), left = a.substr(7, 3), right = a.substr(12, 3);
  
    int s, l, r;
    if(m.count(start)) s = m[start];
    else{
      s = idx; idx++;
      m[start] = s;
      v.push_back({0, 0});
    }

    if(m.count(left)) l = m[left];
    else{
      l = idx; idx++;
      m[left] = l;
      v.push_back({0, 0});
    }

    if(m.count(right)) r = m[right];
    else{
      r = idx; idx++;
      m[right] = r;
      v.push_back({0, 0});
    }

    v[s] = {l, r};
  }

  int i = m["AAA"], j = 0, d = 0;
  while(i != m["ZZZ"]){
    j %= inst.size();

    if(inst[j] == 'L') i = v[i].first;
    else i = v[i].second;

    j++; d++;
  }

  fout << d;
}
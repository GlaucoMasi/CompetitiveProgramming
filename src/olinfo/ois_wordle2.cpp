#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

void solve() {
  string ans = "     ", resp;
  vector<char> opt;

  cout << "? abcde" << endl;
  cin >> resp;
  for(int i = 0; i < 5; i++) if(resp[i] != 'W') opt.push_back('a'+i);

  cout << "? fghij" << endl;
  cin >> resp;
  for(int i = 0; i < 5; i++) if(resp[i] != 'W') opt.push_back('f'+i);

  cout << "? klmno" << endl;
  cin >> resp;
  for(int i = 0; i < 5; i++) if(resp[i] != 'W') opt.push_back('k'+i);

  cout << "? pqrst" << endl;
  cin >> resp;
  for(int i = 0; i < 5; i++) if(resp[i] != 'W') opt.push_back('p'+i);

  cout << "? uvwxy" << endl;
  cin >> resp;
  for(int i = 0; i < 5; i++) if(resp[i] != 'W') opt.push_back('u'+i);

  if(opt.size() < 5) opt.push_back('z');

  int found = 0, last = opt.back(); opt.pop_back();
  for(auto j : opt){
    cout << "? ";
    for(int i = 0; i < 5; i++) cout << j; cout << endl;
    cin >> resp;
    for(int i = 0; i < 5; i++) if(resp[i] == 'G') ans[i] = j, found++;
  }
  
  for(auto &i : ans) if(i == ' ') i = last;
  cout << "! " << ans << endl;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  int t; cin >> t;
  while(t--) solve();
}
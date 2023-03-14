#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n, k;
  cin >> n >> k;

  char c;
  map<string, int> m;
  string best = "", temp = "";
  
  for(int i = 0; i < k; i++){
    cin >> c;
    temp += c;
  }
    
  best = temp;
  m[best] = 1;
  int ans = 1;
  
  for(int i = k; i < n; i++){
    cin >> c;
    temp = temp.substr(1, k-1) + c;

    m[temp]++;

    if(m[temp] > ans){
      best = temp;
      ans = m[temp];
    }
  }

  for(auto c : best) cout << c << " ";
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int mid = 0;
  string s; cin >> s;
  vector<int> freq(26);
  for(auto i : s) freq[i-'A']++;

  for(auto i : freq) if(i%2){
    if(s.size()%2 && !mid) mid = 1;
    else{ 
      cout << "NO SOLUTION";
      return 0;
    }
  }

  mid = -1;
  for(int i = 0; i < 26; i++){
    if(freq[i]%2) mid = i;
    else for(int j = 0; j < freq[i]/2; j++) cout << (char)('A'+i);
  }
  
  if(mid != -1) for(int j = 0; j < freq[mid]; j++) cout << (char)('A'+mid);
  for(int i = 25; i >= 0; i--) if(!(freq[i]%2))for(int j = 0; j < freq[i]/2; j++) cout << (char)('A'+i);
}
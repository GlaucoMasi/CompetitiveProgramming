#include <bits/stdc++.h>
using namespace std;

void calc(int n, int idx){
  char temp = (char)('0'+idx);
  string name = "output_00";
  name += temp;
  name += ".txt";
  ofstream fout(name);

  int tot = n*n+n+1;
  vector<vector<int>> crews;
  
  for(int i = 0; i < n+1; i++){
    vector<int> curr; curr.push_back(0);
    for(int j = 0; j < n; j++) curr.push_back(i*n+j+1);
    crews.push_back(curr);
  }

  for(int i = 1; i <= n; i++) for(int k = 0; k < n; k++){
    vector<int> curr;
    curr.push_back(i);
    for(int j = 0; j < n; j++) curr.push_back((j+1)*n+1 + (j*(i-1)+k)%n);
    crews.push_back(curr);
  }

  for(auto i : crews){
    for(auto j : i) fout << j << " ";
    fout << '\n';
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  vector<int> vals = {5, 7, 13, 19, 23, 31, 47, 61, 83, 97};
  for(int i = 0; i < vals.size(); i++) calc(vals[i], i);
}
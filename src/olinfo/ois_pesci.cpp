#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;
  stack<int> s;

  int tot = 0;
  for(int i = 0; i < n; i++){
    int a, b; fin >> a >> b;

    if(a == 0) s.push(b);
    else{
      if(s.empty()) tot++;
      else{
        while(!s.empty()){
          if(s.top() < b) s.pop();
          else break;
        }
  
        if(s.empty()) tot++;
      }
    }
  }

  tot += s.size();
  fout << tot;
}
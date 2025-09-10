#include <bits/stdc++.h>
using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

string s;
long long num = 0, tot = 0;

void hello(int i){
  i++;

  if(s[i] == 'e'){
    i++;
    if(s[i] == 'l'){
      i++;
      if(s[i] == 'l'){
        i++;
        if(s[i] == 'o'){
          num++;
        }
      }
    }
  }

  return;
}

void world(int i){
  i++;

  if(s[i] == 'o'){
    i++;
    if(s[i] == 'r'){
      i++;
      if(s[i] == 'l'){
        i++;
        if(s[i] == 'd'){
          tot += num;
        }
      }
    }
  }

  return;
}

int main() {
  fin >> s;

  for(int i = 0; i < s.size(); i++){
    if(s[i] == 'h') hello(i);
    if(s[i] == 'w') world(i);
  }

  fout << tot;
}
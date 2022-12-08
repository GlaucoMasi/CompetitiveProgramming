#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;
  string a; fin >> a;

  stack<char> s;  
  for(auto c : a){
    if(c == '<' || c == '(' || c == '[' || c == '{') s.push(c);
    else if(s.empty() || !((c == '>' && s.top() == '<') || (c == ')' && s.top() == '(') || (c == ']' && s.top() == '[') || (c == '}' && s.top() == '{'))){
      fout << "malformata";
      return 0;
    }else s.pop();
  }

  if(s.empty()) fout << "corretta";
  else fout << "malformata";  
}
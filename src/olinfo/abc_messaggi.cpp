#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {

  int N, R;

  fin >> N >> R;

  map<string, vector<string> > inv;
  map<string, vector<string> > ric;

  for(int i = 0; i < N; i++ ){
    string a, b;
    fin >> a >> b;
    
    inv[a].push_back(b);
    ric[b].push_back(a);
  }

  for(int i = 0; i < R; i++){
    string c, d;
    fin >> c >> d;
    
    if(d == "INVIATI"){
      fout << inv[c].size() << " ";
      for(string e : inv[c]){
        fout << e << " ";
      }
      fout << endl;
    }else if(d == "RICEVUTI"){
      fout << ric[c].size() << " ";
      for(string e : ric[c]){
        fout << e << " ";
      }
      fout << endl;
    }
  }
}
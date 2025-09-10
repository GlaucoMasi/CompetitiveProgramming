#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {

int N, C, x;
long long int swaps = 0;
x = 0;

fin >> N >> C;

map<int, int> m; 

for(int i = 0; i < N; i++){
  int a; 
  fin>>a; 
  if(m.count(a)==0){
    m[a] = x;
    swaps += x;
    x++;
  }else{
    swaps += m[a];
  }
}

fout << swaps;

}
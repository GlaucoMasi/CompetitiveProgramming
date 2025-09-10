#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  
  int N, M, K, count, acc, z;
  z = 1;
  acc = 0;
  count = 0;

  fin >> N >> M >> K;

  vector <int> v(N);

  for(int i = 0; i < v.size(); i++){
    fin >> v[i];
  }

  for(int j = 0; j < M; j++){
    
      count+=v[j];
    
  }

  for(int i = 0; i < N-M+1; i++){

    for(z = i+M-1; count < K; z--){
      if(v[z] == 0){
        v[z] = 1;
        acc++;
        count++;
      }
    }

    count+=v[i+M];
    count-=v[i];
  
  }
  
  fout << acc;

}
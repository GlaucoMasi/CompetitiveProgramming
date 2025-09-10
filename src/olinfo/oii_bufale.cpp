#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

long long solve(int N, int* M, int* P){
  vector<pair<int, int>> diff(N);
  long long tot = 0;
  for(int i = 0; i < N; i++){ 
    diff[i] = {M[i] - P[i], i};
    tot += diff[i].first;
  }

  nth_element(diff.begin(), diff.begin()+N/2, diff.end());
  float mediana = diff[N/2].first;

  if(!(N%2)){
    nth_element(diff.begin(), diff.begin()+(N/2)-1, diff.end());
    mediana = (float)((mediana+diff[(N/2)-1].first)/2);
  }

  tot = 0;
  int curr = 0;
  for(int i = 0; i < N; i++){
    if(diff[i].first < mediana){ 
      tot += P[diff[i].second];
      curr++;
    }
    
    if(diff[i].first > mediana){ 
      tot += M[diff[i].second];
    }

    if(diff[i].first == mediana){
      diff.push_back({diff[i]});
    }
  }

  for(int i = N; i < diff.size(); i++){
    if(curr < N/2){
      tot += P[diff[i].second];
      curr++;
    }else{
      tot += M[diff[i].second];
    }
  }

  return tot;
}
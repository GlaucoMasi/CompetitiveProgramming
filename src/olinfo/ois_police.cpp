#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  fin.tie(0);
  fin.sync_with_stdio(0);

  int N, K, tries, P;
  P = 0;
  tries = 0;
  bool found = false;

  fin >> N >> K;
  K--;

  vector<pair<int, bool>> cit;

  for(int i = 0; i < N; i++){
    int a;

    fin >> a;
    a--;

    cit.push_back({a, false});
  }

  while(found == false){

    if(P == K){
      
      found = true;

    }else{

      if(cit[P].second == true){

        fout << -1;
        return 0;

      }else{

        cit[P].second = true;
        P = cit[P].first;
        tries++;

      }
    }
  }

  fout << tries;

}
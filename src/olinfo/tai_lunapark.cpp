#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> father, size;

int get_father(int a){
  if(a == father[a]) return a;
  else return father[a] = get_father(father[a]);
}

bool check(pair<int, int> arco){
  int a = get_father(arco.first);
  int b = get_father(arco.second);

  if(a != b){
    if(size[a] < size[b]) swap(a, b);
    father[b] = a;
    size[a] += size[b];
  }

  return (a != b);
}

int progetta(int N, int M, int K, vector<int> &A, vector<int> &B,
vector<int> &W){
  vector<vector<pair<int, int>>> counting(1001);
  father.resize(N);
  iota(father.begin(), father.end(), 0);
  size.resize(N, 1);

  for(int i = 0; i < M; i++) counting[W[i]].push_back({A[i]-1, B[i]-1});

  int ans = 0;
  for(int i = 1000; i > 0; i--){
    for(auto j : counting[i]){
      if(N == K) return ans;
      else if(check(j)){
        ans += i;
        N--;
      }
    }
  }

  return ans;
}
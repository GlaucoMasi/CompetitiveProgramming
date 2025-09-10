#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> v;
int n;
int t = 0;

bool check(int type, int num){
  if(num + type <= n) return true;
  else return false;
}

bool test(int num){
  
  if(num == n){
    for(int i = 0; i < n; i++){
      if(v[i] == 1){
        fout << "[O]";
      }else if(v[i] == 2){
        fout << "[OOOO]";
        i++;
      }
    }
    fout << endl;

    return true;
  }

  for(int i = 1; i < 3; i++){
    if(check(i, num)){
      num += i;
      v[num-i] = i;
      v[num-1] = i;
      test(num);
      num -= i;
    }
  }

  return false;
}

int main() {
  fin.tie(0);
  fin.sync_with_stdio(0);

  fin >> n;
  v.resize(n);

  test(0);
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int mod = 1e9+7;
struct matrix{
  long long mat[6][6] = {0};
  matrix friend operator *(const matrix &a, const matrix &b){
    matrix ans;
    for(int i = 0; i < 6; i++){
      for(int j = 0; j < 6; j++){
        for(int k = 0; k < 6; k++) ans.mat[i][j] = (ans.mat[i][j] + (a.mat[i][k]*b.mat[k][j])%mod)%mod;
      }
    }
    return ans;
  }
};

matrix base = { {
  {1, 0, 0, 0, 0, 0},
  {0, 1, 0, 0, 0, 0},
  {0, 0, 1, 0, 0, 0},
  {0, 0, 0, 1, 0, 0},
  {0, 0, 0, 0, 1, 0},
  {0, 0, 0, 0, 0, 1},
} };

matrix f(matrix a, long long b){
  if(b == 0) return base;
  if(b == 1) return a;

  matrix ans = f(a, b/2);
  ans = ans*ans;
  if(b%2) ans = ans*a;

  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
  long long n; cin >> n;

  matrix start = { {
    {0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0},
    {0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1},
  } };

  cout << f(start, n).mat[5][5];
}
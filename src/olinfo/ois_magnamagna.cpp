#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

long double t = numeric_limits<long double>::max();
int n;
vector<long double> v;
vector<vector<int>> memo;
vector<vector<pair<char, char>>> dir;
vector<vector<pair<long double, long double>>> cum;
vector<long double> pows;

pair<long double, long double> calc(int l, int r){
  if(cum[l][r].first != t && cum[l][r].second != t) return cum[l][r];

  if(cum[l][r].first == t){
    cum[l][r].first = calc(l-1, r).first;
    cum[l][r].first -= v[l-1];
    cum[l][r].first *= -2;
  }

  if(cum[l][r].second == t){
    cum[l][r].second = calc(l, r+1).second;
    cum[l][r].second -= v[r+1];
    cum[l][r].second *= -2;
  }

  return cum[l][r];
}

int dp(int l, int r){
  if(memo[l][r] != -1) return memo[l][r];
  
  if(l == r){
    dir[l][r].first = 'L';
    return memo[l][r] = v[l];
  }

  if(l == r-1){
    if(v[l] > v[r]){
      dir[l][r] = {'L', 'L'};
      memo[l][r] = v[l];
    }else{
      dir[l][r] = {'R', 'L'};
      memo[l][r] = v[r];
    }

    return memo[l][r];
  }

  int sinistra = v[l]; pair<char, char> tempsin; tempsin.first = 'L';
  pair<long double, long double> next = {0, 0};
  l++;
  for(int i = 0; i <= r-l; i++){
    next.first += v[l+i] * (i%2 ? -1 : 1) * pows[i];
    next.second += v[r-i] * (i%2 ? -1 : 1) * pows[i];
  }
  l--;

  if(next.first > next.second){
    tempsin.second = 'L';
    sinistra += dp(l+2, r);
  }else if(next.second > next.first){
    tempsin.second = 'R';
    sinistra += dp(l+1, r-1);
  }else{
    if(dp(l+1, r-1) > dp(l+2, r)){
      tempsin.second = 'R';
      sinistra += dp(l+1, r-1);
    }else{
      tempsin.second = 'L';
      sinistra += dp(l+2, r);
    }
  }

  int destra = v[r]; pair<char, char> tempdes; tempdes.first = 'R';
  next = {0, 0};
  r--;
  for(int i = 0; i <= r-l; i++){
    next.first += v[l+i] * (i%2 ? -1 : 1) * pows[i];
    next.second += v[r-i] * (i%2 ? -1 : 1) * pows[i];
  }
  r++;

  if(next.first > next.second){
    tempdes.second = 'L';
    destra += dp(l+1, r-1);
  }else if(next.second > next.first){
    tempdes.second = 'R';
    destra += dp(l, r-2);
  }else{
    if(dp(l+1, r-1) > dp(l, r-2)){
      tempdes.second = 'L';
      destra += dp(l+1, r-1);
    }else{
      tempdes.second = 'R';
      destra += dp(l, r-2);
    }
  }

  if(destra > sinistra){
    dir[l][r] = tempdes;
    memo[l][r] = destra;
  }else{
    dir[l][r] = tempsin;
    memo[l][r] = sinistra;
  }

  return memo[l][r];
}

int main() {
  fin >> n;
  v.resize(n); 
  memo.resize(n, vector<int>(n, -1)); dir.resize(n, vector<pair<char, char>>(n, {'/', '/'}));
  cum.resize(n, vector<pair<long double, long double>>(n, {t, t}));
  for(auto &i : v) fin >> i;

  pows.resize(n+1); pows[0] = 1;
  for(int i = 1; i <= n; i++) pows[i] = pows[i-1]/2;

  long double left = 0, right = 0;
  for(int i = 0; i < n; i++){
    left += v[i] * pows[i] * (i%2 ? -1 : 1);
    right += v[n-1-i] * pows[i] * (i%2 ? -1 : 1);

    cum[0][i].first = left;
    cum[n-1-i][n-1].second = right;
  }

  dp(0, n-1);

  int l = 0, r = n-1;
  while(1){
    if(l > r) break;
    
    fout << dir[l][r].first;
    if(l != r) fout << dir[l][r].second;
    else break;

    if(dir[l][r].first == 'L'){
      if(dir[l][r].second == 'L') l += 2;
      else l++, r--;
    }else{
      if(dir[l][r].second == 'L') l++, r--;
      else r -= 2;
    }
  }
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

typedef complex<double> type;
const double pi = acos(-1);

void fft(vector<type> &a, bool invert){
  int n = a.size();
  if(n == 1) return;

  vector<type> l, r;
  for(int i = 0; i < n; i += 2) l.push_back(a[i]);
  for(int i = 1; i < n; i += 2) r.push_back(a[i]);
  fft(l, invert);
  fft(r, invert);
  
  type w(1), inc = polar(1.0, ((2*pi/n)*(invert ? -1 : 1)));
  for(int i = 0; i < n/2; i++){
    a[i] = l[i] + w*r[i];
    a[i+n/2] = l[i] - w*r[i];
    if(invert) a[i] /= 2, a[i+n/2] /= 2;
    w *= inc;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int k, n, m; cin >> k >> n >> m;
  int sz = 1; while(sz <= 2*k) sz *= 2;
  vector<long long> a(sz), b(sz);

  for(int i = 0; i < n; i++){
    int t; cin >> t;
    a[t]++;
  }

  for(int i = 0; i < m; i++){
    int t; cin >> t;
    b[t]++;
  }

  vector<type> ca(a.begin(), a.end()), cb(b.begin(), b.end());
  fft(ca, false);
  fft(cb, false);

  for(int i = 0; i < sz; i++) ca[i] *= cb[i];
  fft(ca, true);

  for(int i = 2; i <= 2*k; i++) cout << (long long)round(ca[i].real()) << " ";
}
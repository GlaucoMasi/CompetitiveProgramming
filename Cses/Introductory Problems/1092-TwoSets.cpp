#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  int n; cin >> n;
  vector<int> v1, v2;
  long long a = 0, b = 0;
  for(int i = n; i >= 2; i -= 2){
    v1.push_back(i);
    v2.push_back(i-1);
    a += i; b += i-1;
    swap(v1, v2); swap(a, b);
  }

  if(n%2){
    if(a < b) v1.push_back(1), a++;
    else v2.push_back(1), b++;
  }

  if(a != b){
    cout << "NO";
    return 0;
  }else{
    cout << "YES\n";
    cout << v1.size() << '\n';
    for(auto i : v1) cout << i << " ";
    cout << '\n' << v2.size() << '\n';
    for(auto i : v2) cout << i << " ";
  }
}
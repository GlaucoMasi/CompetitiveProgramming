#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  unordered_set<int> zeros;
  zeros.insert(0);
  zeros.insert(1);
  zeros.insert(2);
  zeros.insert(4);
  zeros.insert(7);
  zeros.insert(10);
  zeros.insert(20);
  zeros.insert(23);
  zeros.insert(26);
  zeros.insert(50);
  zeros.insert(53);
  zeros.insert(270);
  zeros.insert(273);
  zeros.insert(276);
  zeros.insert(282);
  zeros.insert(285);
  zeros.insert(288);
  zeros.insert(316);
  zeros.insert(334);
  zeros.insert(337);
  zeros.insert(340);
  zeros.insert(346);
  zeros.insert(359);
  zeros.insert(362);
  zeros.insert(365);
  zeros.insert(386);
  zeros.insert(389);
  zeros.insert(392);
  zeros.insert(566);
  zeros.insert(630);
  zeros.insert(633);
  zeros.insert(636);
  zeros.insert(639);
  zeros.insert(673);
  zeros.insert(676);
  zeros.insert(682);
  zeros.insert(685);
  zeros.insert(923);
  zeros.insert(926);
  zeros.insert(929);
  zeros.insert(932);
  zeros.insert(1222);

  int t; cin >> t;
  while(t--){
    int a; cin >> a;
    if(zeros.count(a)) cout << "second\n";
    else cout << "first\n";
  }
}
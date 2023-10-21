#include <bits/stdc++.h>
using namespace std;

struct node{
  vector<int> next = vector<int>(27, -1);
  int prev = -1;
  int sons = 0, takensons = 0;
};

int idx = 1;
vector<node> trie(2e6);

int main() {
  int n; cin >> n;
  vector<string> v(n); vector<int> end(n);
  for(auto &i : v) cin >> i;

  int tot = 0;
  trie[0].sons = n;

  int curr, next;
  for(int i = 0; i < n; i++){
    auto str = v[i];
    curr = 0;
    for(int j = 0; j < str.size(); j++){
      if(trie[curr].next[str[j]-'a'] == -1){
        trie[curr].next[str[j]-'a'] = idx++;
        trie[curr].sons++;
      }

      next = trie[curr].next[str[j]-'a'];
      trie[next].prev = curr;
      curr = next;
    }

    trie[curr].sons++;
    end[i] = curr;
  }

  for(int i = 0; i < n; i++){
    int curr = end[i];
    tot++; trie[curr].takensons++;

    while(curr != -1){
      if(trie[curr].sons == trie[curr].takensons){
        tot -= trie[curr].takensons; tot++;
        trie[trie[curr].prev].takensons++;
        curr = trie[curr].prev;
      }else break;
    }

    cout << tot << '\n';
  }
}
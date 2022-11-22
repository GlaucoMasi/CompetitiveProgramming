#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  int n; fin >> n;

  int a = -1;
  deque<int> dq;
  for(int i = 0; i < n; i++){
    if(a == -1) fin >> a;

    bool t = 1;
    if(dq.empty()) dq.push_front(a);
    else if(dq.front() == a) dq.pop_front();
    else if(dq.front() > a){
      int t = dq.front()-a;
      dq.push_front(a);
      dq.push_front(t);
    }else{
      a -= dq.front();
      dq.pop_front();
      t = 0;
      i--;
    }

    if(t) a = -1;
  }

  fout << dq.size() << endl;
  while(!dq.empty()){
    fout << dq.back() << " ";
    dq.pop_back();
  }
}
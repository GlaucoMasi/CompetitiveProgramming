#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int n, done = 1, tot = 0;
vector<int> v;
vector<pair<int, int>> lista;

int find(){
  int i = done;
  while(i+1 < 2*n+1 && v[i] != v[i+1]) i++;
  return i;
}

int last(){
  int i = 2*n+1;
  while(v[i] + v[i-1] != 3 && i > 1) i--;
  return i-1;
}

int main() {
  fin >> n;
  v.resize(2*n+2, 0);
  for(int i = 0; i < n; i++) v[i] = 1;
  for(int j = n; j < 2*n; j++) v[j] = 2;

  int l = 1, r = 2*n+1;
  int hole = 2*n;

  if(!(n % 2)){
    swap(v[n-1], v[2*n]);
    swap(v[n], v[2*n+1]);

    lista.push_back({n, 2*n+1});

    swap(v[0], v[n-1]);
    swap(v[1], v[n]);

    lista.push_back({1, n});

    swap(v[2*n], v[0]);
    swap(v[2*n+1], v[1]);

    lista.push_back({2*n+1, 1});
    
    tot += 3;
    done = 3;
  }
  
  while(1){
    if(done+1 == 2*n) break;
    
    int a = find();
    lista.push_back({a+1, hole+1});
    swap(v[hole], v[a]);
    swap(v[hole+1], v[a+1]);
    hole = a;

    int next = last();
    lista.push_back({next+1, hole+1});
    swap(v[hole], v[next]);
    swap(v[hole+1], v[next+1]);
    hole = next;

    done += 2;
    tot += 2;
  }

  fout << tot << " " << n << endl;
  for(auto i : lista) fout << i.first << " " << i.second << endl;
}
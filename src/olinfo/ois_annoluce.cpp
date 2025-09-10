#include <bits/stdc++.h>

using namespace std;

ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {

  long long int N, Q, x, y, z, a, q, som, ind;
  som = 0;

  vector<long long> dist;

  fin >> N;

  for(int i = 0; i < N; i++){

    fin >> x >> y >> z;

    long long int a = x*x + y*y + z*z;

    dist.push_back(a);

  }

  sort(dist.begin(), dist.end());

  fin >> Q;

  for(int i = 0; i < Q; i++){

    fin >> q;

    q *= q;

    auto it = upper_bound(dist.begin(), dist.end(), q);

    ind = it - dist.begin();

    fout << ind << endl; 

  } 
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int main() {
  long long int a, b, c;
  fin >> a >> b >> c;

  fout << ((c - 24 + b) / 24) * (b - a) + (((c - 24 + b) % 24) > a ? (b <= ((c - 24 + b) % 24)) ? (b - a) : (((c - 24 + b) % 24) - a) : 0);
}
#include <bits/stdc++.h>
using namespace std;
ofstream fout("output.txt");

int main() {
  ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

  FILE* fin = fopen("input.txt", "r");

  int n; fscanf(fin, "%d\n", &n);
  while(n--){
    char c = fgetc(fin);
    if(c >= 'a' && c <= 'z') c += ('A'-'a');
    else if(c >= 'A' && c <= 'Z') c += ('a'-'A');
    fout << c;
  }
}
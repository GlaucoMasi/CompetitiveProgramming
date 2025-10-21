#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

vector<int> dist;
vector<vector<int>> g;
void f(int i, int p){
    if(p != -1) dist[i] = dist[p]+1;
    for(auto j : g[i]) if(j != p) f(j, i);
}

int main() {
    int n; fin >> n;
    g.resize(n);

    for(int i = 0; i < n-1; i++){
        int a, b; fin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    dist.resize(n, 0);
    f(0, -1);

    int idx = max_element(dist.begin(), dist.end())-dist.begin();
    fill(dist.begin(), dist.end(), 0);
    f(idx, -1);

    fout << 2*(*max_element(dist.begin(), dist.end()));
}
#include <bits/stdc++.h>
using namespace std;

int n, tot = 0;
long long ans = 0;
vector<vector<int>> g;
vector<int> distUp, distDown, nxt;

bool find(int i, int p){
    if(i == n-1) return true;
    for(auto j : g[i]){
        if(j == p) continue;
        if(find(j, i)){
            nxt[i] = j;
            tot++;
            return true;
        }
    }
    return false;
}

void calc_up(int i, int p, int up){
    if(g[i].size() > (i != 0) + (nxt[i] != -1)) up = 1;
    distUp[i] = up;
    if(nxt[i] != -1) calc_up(nxt[i], i, up+1);
}

int calc_down(int i, int p){
    if(g[i].size() > (i != 0) + (nxt[i] != -1)) distDown[i] = 1;
    for(auto j : g[i]){
        if(j == p) continue;
        distDown[i] = min(distDown[i], calc_down(j, i));
    }
    return distDown[i]+1;
}


long long atterra(int N, vector<int> u, vector<int> v) {
    n = N;
    g.resize(n);
    for(int i = 0; i < n-1; i++){
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
    }
    nxt.resize(n, -1);
    find(0, -1);
    if(tot == n-1) return -1;
    distUp.resize(n, 1e9); distDown.resize(n, 1e9);
    calc_up(0, -1, 1e9);
    calc_down(0, -1);
    long long ans = 0;
    for(int i = 0; i < n; i++)
        if(nxt[i] != -1 || i == n-1)
            ans += min(distUp[i], distDown[i]);
    return ans;
}


#ifndef EVAL

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    int N; cin >> N;

    vector<int> U(N - 1), V(N - 1);
    for(int i = 0; i < N - 1; ++i)
        cin >> U[i] >> V[i];

    cout << atterra(N, U, V) << endl;
}

#endif
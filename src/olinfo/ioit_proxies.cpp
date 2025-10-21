#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

#define MAXN 1024000

int n, e, tot;
set<pair<int, int>> nxt[MAXN];
int p[MAXN], height[MAXN], v[MAXN];

bool recalc(int i, int start){
    if(i == start) return true;
    int newheight = nxt[i].empty() ? 0 : nxt[i].rbegin()->first + 1;

    if(p[i] == -1){
        height[i] = newheight;
        return false;
    }
    
    if(newheight == height[i]) return false;
    nxt[p[i]].erase(make_pair(height[i], i));
    height[i] = newheight;
    nxt[p[i]].insert(make_pair(height[i], i));
    return recalc(p[i], start);
}

void disconnect(int i){
    if(p[i] == -1) return;
    nxt[p[i]].erase(make_pair(height[i], i));
    recalc(p[i], -1);
    p[i] = -1;
}

bool connect(int j, int i){
    if(p[j] != -1) disconnect(j);
    nxt[i].insert(make_pair(height[j], j));
    if(recalc(i, j)) return true;  
    p[j] = i;
    return false;
}

void init(){
    for(int i = 0; i < n+e; i++) p[i] = -1;
    for(int i = 1; i < n; i++) connect(i, v[i]);
    tot = height[0];
}

char emergency(int c, int k, vector<int> &s){
    for(int i = 0; i < k; i++) connect(s[i], n);
    if(connect(n++, c)) return 'c';

    char ans = height[0] > tot ? '1' : '0';
    tot = height[0];
    return ans;
}

int main() {
    fin >> n >> e;
    for(int i = 0; i < n; i++) fin >> v[i];
    
    init();

    for(int i = 0; i < e; i++){
        int c, k; fin >> c >> k;
        vector<int> s(k); for(int j = 0; j < k; j++) fin >> s[j];
        char ans = emergency(c, k, s);
        fout << ans;
        if(ans == 'c') break;
    }
    
    fout << '\n';
}
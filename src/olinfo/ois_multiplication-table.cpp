#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define i128 __int128_t

int n, m;
vector<vector<pair<int, ll>>> rows, cols;
bool test(){
    ll r0 = -1, c0 = -1;
    vector<ll> r(n, -1), c(m, -1);

    auto test_line = [&](vector<pair<int, ll>> &line, int i, bool isRow){
        if(line.size() < 2) return true;
        auto [j1, v1] = line[0];
        auto [j2, v2] = line[1];

        ll num = v2-v1, den = j2-j1;
        if(!den || num%den || num/den <= 0) return false;

        ll q = num/den;
        if(isRow) r[i] = q, r0 = r[i]-i;
        else c[i] = q, c0 = c[i]-i;
        return true;
    };

    for(int i = 0; i < n; i++) if(!test_line(rows[i], i, true)) return false;
    for(int i = 0; i < m; i++) if(!test_line(cols[i], i, false)) return false;
    
    if(r0 != -1 && c0 == -1){
        int i = 0;
        while(rows[i].empty()) i++;
        
        auto [j, v] = rows[i][0];
        if(i+r0 <= 0 || v%(i+r0) || v/(i+r0)-j <= 0) return false;
        
        c0 = v/(i+r0)-j;
    }else if(r0 == -1 && c0 != -1){
        int j = 0;
        while(cols[j].empty()) j++;
        
        auto [i, v] = cols[j][0];
        if(j+c0 <= 0 || v%(j+c0) || v/(j+c0)-i <= 0) return false;
        
        r0 = v/(j+c0)-i;     
    }
    
    if(r0 != -1 && c0 != -1){
        if(r0 < 1 || c0 < 1) return false;
        for(int i = 0; i < n; i++){
            for(auto [j, v] : rows[i]){
                i128 a = (r0+i), b = (c0+j);
                if((i128)v != a*b) return false;
            }
        }
        return true;
    }

    vector<tuple<int, int, ll>> all;
    for(int i = 0; i < n; i++) for(auto [j, v] : rows[i]) all.push_back({i, j, v});

    if(all.empty()) return true;
    auto [i0, j0, v0] = all[0];

    auto try_cands = [&](ll c0, ll r0){
        bool ok = true;
        if(r0 < 1 || c0 < 1) return false;
        for(auto [i, j, v] : all){
            i128 a = (r0+i), b = (c0+j);
            if((i128)v != a*b) ok = false;
        }
        return ok;
    };

    for(ll d = 1; d*d <= v0; d++) if(!(v0%d)){
        ll r0 = d-i0, c0 = v0/d-j0;
        if(try_cands(v0/d-j0, d-i0) || try_cands(d-j0, v0/d-i0)) return true;
    }

    return false;
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;

    rows.resize(n);
    cols.resize(m);
    
    for(int i = 0; i < n; i++) for(int j = 0; j < m; j++){
        string s; cin >> s;
        if(s != "?"){
            ll v = stoll(s);
            rows[i].push_back({j, v});
            cols[j].push_back({i, v});
        }
    }

    cout << (test() ? "YES" : "NO");
}
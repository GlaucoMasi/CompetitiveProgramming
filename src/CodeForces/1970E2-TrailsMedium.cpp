#include <bits/stdc++.h>
using namespace std;
const int M = 100;
const int mod = 1e9+7;
template<size_t N, int mod>
class Matrix {
public:
    int mat[N][N];
    Matrix() {
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                mat[i][j] = 0;
    }
    Matrix operator*(Matrix& other) {
        Matrix ans;
        for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
                for(int k = 0; k < N; k++)
                    ans.mat[i][j] = (ans.mat[i][j] + (1LL*mat[i][k]*other.mat[k][j])%mod)%mod;
        return ans;
    }
    int getans() {
        int ans = 0;
        for(int i = 0; i < N; i++) ans = (ans+mat[0][i])%mod;
        return ans;
    }
};
Matrix<M, mod> base;
Matrix<M, mod> binexp(Matrix<M, mod> b, int exp){
    if(exp == 0) return base;
    if(exp == 1) return b;
    Matrix<M, mod> ans = binexp(b, exp/2);
    ans = ans*ans;
    if(exp%2) ans = ans*b;
    return ans;
}
int main() {
    Matrix<M, mod> start;
    int n, m; cin >> m >> n;
    vector<int> s(m), l(m);
    for(auto &i : s) cin >> i;
    for(auto &i : l) cin >> i;
    for(int i = 0; i < m; i++)
        for(int j = 0; j < m; j++)
            start.mat[i][j] = s[i]*(l[j]+s[j])+l[i]*s[j];
    for(int i = 0; i < m; i++) base.mat[i][i] = 1;
    cout << binexp(start, n).getans();
}
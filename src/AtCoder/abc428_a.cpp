#include <bits/stdc++.h>
using namespace std;

int main() {
    int s, a, b, x; cin >> s >> a >> b >> x;
    cout << s*a*(x/(a+b)) + s*min(a, x%(a+b));
}
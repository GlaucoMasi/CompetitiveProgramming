#include <bits/stdc++.h>
using namespace std;

int main() {
    int q; cin >> q;
    
    string s = "";
    stack<int> fails;
    int sum = 0, length = 0;
    while(q--){
        int t; cin >> t;
        if(t == 1){
            char c; cin >> c;
            s += c;
            if(c == '(') sum++;
            else sum--;
            if(sum < 0) fails.push(length);
            length++;
        }else{
            if(s.back() == '(') sum--;
            else sum++;
            s.pop_back();
            length--;
            if(!fails.empty() && fails.top() == length) fails.pop();
        }

        cout << ((fails.empty() && sum == 0) ? "Yes\n" : "No\n");
    }
}
#include <bits/stdc++.h>
using namespace std;
ifstream fin("input.txt");
ofstream fout("output.txt");

int mcd(int a, int b){
    while(a != b){
        if(a > b) a -= b;
        else b -= a;
    }

    return a;
}

int main(){
    int a, b;
    fin >> a >> b;
    
    vector<int> v(a, 0);
    
    fout << a / mcd(a, b) << " ";
    
    b = 20;
    while(mcd(a, b) != 1) b++;
    fout << b;  
}
#include <bits/stdc++.h>

using namespace std;

int main () {
    
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
	
	long long int N,h,b,q;

	cin >> N;
	
	if(N%2!=0){
	cout << (N/2+1)*(N/2+2);
	}else{
	cout << (N/2+1)*(N/2+1);
	}
}
#include <bits/stdc++.h>

using namespace std;

int main () {
    
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	
	long long int N, K, lil, temp;
	lil=0;
	
	cin >> N >> K;
	
	int v[N];
	
	for(int i=0; i<N; i++){
		cin >> v[i];
		if(i<K){
			lil+=v[i];
		}
	}
	
	temp=lil;

	for(int s=1; s<N-K+1; s++){  
		temp=temp-v[s-1]+v[s+K-1];
		lil=min(lil, temp);
	}
	
	cout << lil;
	
}
#include <bits/stdc++.h>

using namespace std;

int main () {
	
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
	
	long long int N=0;
	long long int suff=-1;
	long long int insuff=-1;
	
	cin >> N;
	
	int v[N];
	
	for(int n=0; n<N; n++){
		cin >> v[n];
	}
	
	for(int i=N-1; i>=0; i--){
        if(v[i]>5){
	        suff=i;
	        i=-10;
        }
	}
	
	for(int j=0; j<N; j++){
        if(v[j]<6){
	        insuff=j;
	        j=N+10;
        }
	}
	
    if(suff!=-1 && insuff!=-1 && suff>insuff){
        cout << suff-insuff+1;
    }else if(suff==-1 || insuff==-1 || insuff>suff){
        cout << "-1";
    }
}
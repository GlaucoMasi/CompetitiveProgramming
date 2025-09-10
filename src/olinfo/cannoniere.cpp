//https://training.olinfo.it/#/task/cannoniere/statement
#include <bits/stdc++.h>

using namespace std;

int main () {

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
	
	long long int G, N, R;
	int v[101]={0};
	long long int magg=0;
	int num;
	
	cin >> N;
	
	for(int i=0; i<N; i++){
		cin >> G >> R;
		v[G]+=R;
	}
	
	for(int j=0; j<=100; j++){
		if(v[j]>magg){
			magg=v[j];
			num=j;
		}
	}
	
	cout << num << " " << magg;
}
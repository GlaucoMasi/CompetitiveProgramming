//training.olinfo.it/#/task/ois_ceo/statement
#include <bits/stdc++.h>

using namespace std;

int main () {
	
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
	
	long long int N;
	long long int tot=0;
	cin >> N;
	long long int l[N];
	long long int lv[N];
	lv[0]=1;
	l[0]=1;
	
	for(int i=1; i<=N; i++){
		cin >> l[i];
	}
	
	for(int k=1; k<=N; k++){
		lv[k]=l[k]*lv[k-1];
		tot+=lv[k];
	}
	
	cout << tot+1;

}
//training.olinfo.it/#/task/ois_ceo/statement
#include <bits/stdc++.h>

using namespace std;

int main () {

	long long int N, K, T, mas, sum;
	sum=0;
	mas=0;
	
	cin >> N >> K;
	
	long long int muffin[N+1];
	muffin[0]=0;
	for(int i=1; i<=N; i++){
		cin >> muffin[i];
	}

	for(int j=1; j<=K; j++){
		mas+=muffin[j];
		sum=mas;
	}

	for(int s=2; s<=N-K+1; s++){
		sum=sum-muffin[s-1]+muffin[s+K-1];
		mas=max(mas, sum);
	}
	
	cout << mas;

}
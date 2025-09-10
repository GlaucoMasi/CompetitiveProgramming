//training.olinfo.it/#/task/spartizione/statement
#include <bits/stdc++.h>

using namespace std;

int main () {

freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

	int N, M, K, pr, trash, u, d;
	
	cin >> N >> M >> pr;
	
	for(int i=0; i<N-1; i++){
		cin >> trash;
	}
	
	for(int j=0; j<M; j++){
		cin >> u >> d;
		if(pr==d){
			pr=u;
		}
	}
	
	cout << pr;
}
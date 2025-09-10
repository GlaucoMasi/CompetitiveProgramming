//training.olinfo.it/#/task/spartizione/statement
#include <bits/stdc++.h>

using namespace std;

int main () {
	
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

	int M, uno, due, pr;
	pr=0;
	
	cin >> M >> M;
	
	for(int i=0; i<M; i++){
		cin >> uno >> due;
		if(uno==pr){
			pr=due;
		}else if(due==pr){
			pr=uno;
		}
	}
	
	cout << pr;
}
#include <bits/stdc++.h>

using namespace std;

int main () {
	
	long long int N, M, a, tot, M2;
	tot=0;
	vector <int> kids;
	
	cin >> N >> M;

	for(int s=0; s<N; s++){
		cin >> a;
		kids.push_back(a);
		tot+=a;
	}
	
	M2=M%tot;
	
	if(M2==0){
		cout << N-1;
	}else{
		for(int s=0; N>0; s++){
		M2-=kids[s];;
			if(M2<=0){
				cout << s;
				break;
			}
		}	
	}
}
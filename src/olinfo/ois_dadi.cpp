//https://training.olinfo.it/#/task/dadi/statement
#include <bits/stdc++.h>

using namespace std;

void X(int &T, int &F){

	int temp;
	temp=7-F;
	F=T;
	T=temp;	

}

void Z(int &F, int &R){

	int temp;
	temp=7-R;
	R=F;
	F=temp;

}

void Y(int &R, int &T){

	int temp;
	temp=7-T;
	T=R;
	R=temp;

}

int main () {
    
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
	
	int T=1;
	int F=2;
	int R=3;
	long long int N;
	int temp;
	char azione;

	cin >> N;

	for(int i=0; i<N; i++){
		cin >> azione;
		if(azione=='Z'){
			Z(F, R);
		}else if(azione=='X'){
			X(T, F);
		}else if(azione=='Y'){
		Y(R, T);
		}else if(azione=='F'){
		cout << F << " ";
		}else if(azione=='T'){
		cout << T << " ";
		}else if(azione=='R'){
		cout << R << " ";
		}
	}
}
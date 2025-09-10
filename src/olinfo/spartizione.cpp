//training.olinfo.it/#/task/spartizione/statement
#include <bits/stdc++.h>

using namespace std;

int main () {
	
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);

	int gemme;			
	int persone;
	int toto=0;
	
	cin >> gemme >> persone;
	
	if(gemme==persone){
		cout << "1";
	}else{
		for(int i=0; i<1000; i++){
			if(gemme-persone-i>=0){
				gemme=gemme-persone-i;
				toto=toto+i+1;
			}else if(gemme>i+1){
				toto=toto+i+1;
				i=1000000;
			}else{
				toto=toto+gemme;
				i=1000000;
			}
		}
		
		cout << toto;
	}	
}
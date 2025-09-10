#include <bits/stdc++.h>

using namespace std;

int main () {
	
	int N, M, a, bipasso, L10, L16, tot;
	string b;
	vector< pair<int,string> > pl;
	tot=0;
	L16=0;
	L10=0;
	bipasso=0;
	
	cin >> N >> M;
	
	for(int s=0; s<N; s++){
		cin >> a;
		pl.push_back(make_pair(a, ""));
	}

	for(int s=0; s<N; s++){
		cin >> b;
		pl[s].second=b;
	}
	
	sort(pl.begin(), pl.end(), greater<pair<int,string> >() );
	
	for(int s=0; s<M; s++){
		cin >> b;
		if(b=="bipasso"){
			bipasso++;
		}else if(b=="L10"){
			L10++;
		}else if(b=="L16"){
			L16++;
		}
	}
	
	for(int s=0; s<N; s++){
		if(pl[s].second=="L16" && L16!=0){
			tot+=pl[s].first;
			L16--;
		}else if(pl[s].second=="L10" && L10!=0){
			tot+=pl[s].first;
			L10--;
		}else if((pl[s].second=="L10" && L10==0 && bipasso!=0)||(pl[s].second=="L16" && L16==0 && bipasso!=0)){
			tot+=pl[s].first;
			bipasso--;
		}
	}
	
	cout << tot;
}
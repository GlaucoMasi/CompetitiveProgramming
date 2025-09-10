#include <bits/stdc++.h>

using namespace std;

int main () {
	
	int V, N, events, temp, l;
	events=0;
	l=0;
	
	cin >> N >> V;
	
	int n[N];
	int v[V];
	
	for(int i=0; i<N; i++){
		cin >> n[i];
	}
	
	sort(n, n+N);
	
	for(int z=0; z<V; z++){
		cin >> temp;
		if(temp>=n[0]){
			v[z]=temp;
		}else{
			V--;
			z--;
		}
	}
	
	sort(v, v+V);

	for(int s=0, l=0; s<V && l<N; s++){
		if(v[s]>=n[l]){
			events++;
			l++;
		}
	}
	
	cout << events;
}
#include <bits/stdc++.h>
using namespace std;

int mod = 1e9+7;
int fact[200001], inv[200001];

int exp(int b, int e){
	if(e == 0) return 1;
	if(e == 1) return b;

	int ans = exp(b, e/2);
	ans = ((long long)ans*ans)%mod;
	if(e%2) ans = ((long long)ans*b)%mod;
	return ans;
}

int calc(int a, int b){
	return ((long long)fact[a]*exp(fact[a-b], mod-2))%mod;
}

int32_t main() {
	fact[0] = 1;
	for(int i = 1; i <= 2e5; i++) fact[i] = ((long long)fact[i-1]*i)%mod;

	int n; cin >> n;
	vector<int> a(n), b(n);
	for(auto &i : a) cin >> i;
	for(auto &i : b) cin >> i;

	vector<int> here(n);
	sort(a.begin(), a.end());
	for(auto i : b){
		int idx = lower_bound(a.begin(), a.end(), i)-a.begin();
		
		if(idx == n){
			cout << 0;
			return 0;
		}
		
		here[idx]++;
	}

	int ans = 1, done = 0;
	for(int i = n-1; i >= 0; i--){
		if(!here[i]) continue;
		
		if(here[i] > n-i-done){
			cout << 0;
			return 0;
		}

		ans = ((long long)ans*calc(n-i-done, here[i]))%mod;
		done += here[i];
	}

	cout << ans;
}
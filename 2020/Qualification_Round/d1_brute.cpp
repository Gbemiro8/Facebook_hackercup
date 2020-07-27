#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
	int _T; cin >> _T;
	auto solve = [&](){
		ll n,M; cin >> n >> M;
		vector<ll> dp(n), arr(n);
		for(ll &x : arr) cin >> x;
		for(ll i = 0; i < n; i++) dp[i] = LLONG_MAX;
		for(ll i = 0; i < M+1 && i < n; i++) dp[i] = 0;
		for(ll i = M+1; i < n; i++){
			for(ll j = i-M; j < i && j >= 0; j++){
				if(arr[j] == 0) continue;
				dp[i] = min(dp[i], dp[j]+arr[j]);
			}
		}
		if(dp[n-1] == LLONG_MAX || dp[n-1] < 0) dp[n-1] = -1;
		cout << dp[n-1] << "\n";
	};
	for(int xx = 1; xx <= _T; xx++){
		cout << "Case #" << xx << ": ";
		solve();
	}
}

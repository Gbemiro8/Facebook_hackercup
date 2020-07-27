#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
	int _T; cin >> _T;
	auto solve = [&](){
		int n,M; cin >> n >> M;
		vector<ll> dp(n), arr(n);
		for(ll &x : arr) cin >> x;
		for(int i = 0; i < n; i++) dp[i] = LLONG_MAX;
		for(int i = 0; i < M+1 && i < n; i++) dp[i] = 0;
		deque<int> dq;
		dq.push_back(0);
		for(int i = 1; i < M+1; i++){
			while(dq.size() && dp[i] < arr[dq.front()]){
				dq.pop_front();
			}
			dq.push_front(i);
		}
		for(int i = M+1; i < n; i++){
			while(dq.size() && dq.front() < i-M) dq.pop_front();
			if(arr[dq.front()]) dp[i] = min(dp[i], dp[dq.front()]+arr[dq.front()]);
			while(dq.size() && dp[i] < arr[dq.front()]) dq.pop_front();
			dq.push_front(i);
		}
		if(dp[n-1] == LLONG_MAX || dp[n-1] < 0) dp[n-1] = -1;
		cout << dp[n-1] << "\n";
	};
	for(int xx = 1; xx <= _T; xx++){
		cout << "Case #" << xx << ": ";
		solve();
	}
}

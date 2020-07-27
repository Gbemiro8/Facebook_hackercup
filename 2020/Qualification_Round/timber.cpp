#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
	int _T; cin >> _T;
	auto solve = [&](){
		int n; cin >> n;
		vector<pair<int,int>> arr(n);
		for(int i = 0; i < n; i++){
			int x,y;
			cin >> x >> y;
			arr[i] = make_pair(x,y);
		}
		sort(arr.begin(), arr.end());
		ll ans = 0;
		map<ll,ll> m;
		for(int i = 0; i < n; i++){
			int a = arr[i].first, b = arr[i].second;
			m[a+b] = max(m[a+b], m[a] + b);
			m[a] = max(b+m[a-b], m[a]);
			ans = max({ans, m[a], m[a+b]});
		}
		cout << ans << "\n";
	};
	for(int xx = 1; xx <= _T; xx++){
		cout << "Case #" << xx << ": ";
		solve();
	}
}

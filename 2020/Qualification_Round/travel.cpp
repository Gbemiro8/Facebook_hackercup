#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
const char N = 'N', Y = 'Y';
vector<int> adj[55];
vector<int> vis(55);
void dfs(int cur, int x, vector<string> &ans){
	if(vis[cur]) return;
	vis[cur] = 1;
	for(auto e : adj[cur]){
		ans[x][cur] = Y;
		ans[x][e] = Y;
		ans[cur][e] = Y;
		dfs(e,x, ans);
	}
}
int main()
{
	int _T; cin >> _T;
	auto solve = [&](){
		memset(adj, 0, sizeof(adj));
		int n; cin >> n;
		for(int i = 0; i < n; i++) vis[i] = 0;
		string in, out;
		cin >> in >> out;
		vector<string> ans(n);
		for(int i = 0; i < n; i++){
			string tmp = "";
			for(int j = 0; j < n; j++){
				tmp += N;
			}
			ans[i] = tmp;
		}
		for(int i = 0; i < n; i++){
			if(i-1 >= 0){
				if(out[i] == Y && in[i-1] == Y) adj[i].push_back(i-1);
			}
			if(i+1 < n){
				if(out[i] == Y && in[i+1] == Y) adj[i].push_back(i+1);
			}
			adj[i].push_back(i);
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++) vis[j] = 0;
			dfs(i,i, ans);
		}
		for(int i = 0; i < n; i++){
			for(int j = 0; j < n; j++){
				cout << ans[i][j];
			}
			cout << "\n";
		}
	};
	for(int xx = 1; xx <= _T; xx++){
		cout << "Case #" << xx << ": " << "\n";
		solve();
	}
}

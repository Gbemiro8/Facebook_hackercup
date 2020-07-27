#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
int main()
{
	int _T; cin >> _T;
	auto solve = [&](){
		int n; cin >> n;
		string s; cin >> s;
		int A = 0, B = 0;
		for(char x : s){
			A += x == 'A';
			B += x == 'B';
		}
		if(A == B+1 || B == A+1){
			cout << "Y\n";
		} else cout << "N\n";
	};
	for(int xx = 1; xx <= _T; xx++){
		cout << "Case #" << xx << ": ";
		solve();
	}
}

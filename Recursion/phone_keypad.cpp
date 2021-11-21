/*    Author : Prakhar Rai    */
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define LB(x,num) lower_bound(x.begin(),x.end(),num) - x.begin()
#define UB(x,num) upper_bound(x.begin(),x.end(),num) - x.begin()
#define BS(x,num) binary_search(x.begin(),x.end(),num)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define vci vector<int>
#define vcll vector<ll>
#define vcd vector<long double>
#define line(x) sort(x.begin(),x.end())
#define all(x) x.begin(),x.end()
#define newl "\n"
#define vc vector
#define loop(i,a,b) for(int i = a; i < b; i++)
#define lol(i,a,b) for(ll i = a; i < b; i++)
#define lod(i,a,b) for(ld i = 0; i < b; i++)
#define mod 1000000007
#define read(v,n) lol(i,0,n) {ll x; cin >> x; v.pb(x);}
#define run(a,x) for(auto x : a)
#define yes "YES"
#define no "NO"
ll cnt;
using namespace std;
// ll dp[10000000];
// memset(dp, -1, sizeof(dp));

void print_string(map<ll , list<char>> mob, vcll num, string ans, ll index) {
	if (index == num.size()) {
		cout << ans << newl;
		return;
	}

	if (num[index] == 0 or num[index] == 1) {
		print_string(mob, num, ans, index + 1);
	} else {
		for (auto x : mob[num[index]]) {
			print_string(mob, num, ans + x, index + 1);
		}
	}
}

void solve() {
	map<ll , list<char>> mobile;
	ll l;
	for (ll i = 2; i < 10; i++) {
		if (i == 7 or i == 9) {
			l = 4;
		} else {
			l = 3;
		}
		for (ll j = 1; j <= l; j++) {
			mobile[i].pb(char('A' + cnt));
			cnt++;
		}
	}

	string n; cin >> n;
	vcll number;
	for (auto x : n) {
		number.pb(x - 48);
	}

	print_string(mobile, number , "", 0);

}

// FILE WITH TEST CASE

void init() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main() {
	init();
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve();
}
/* This is my journey and i shall endure the work to reach the top .*/
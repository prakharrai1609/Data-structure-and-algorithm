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
ll cnt = 0;
using namespace std;
// ll dp[10000000];
// memset(dp, -1, sizeof(dp));

ll count_coins_BU(vcll coins, ll amt) {
	vcll dp(amt + 1 , INT_MAX);
	dp[0] = 0;
	for (ll i = 1; i <= amt; i++) {
		for (auto c : coins and dp[i - c] != INT_MAX) { // we are putting this second statement to avoid causing INT_MAX + 1
			if (i - c >= 0) {
				dp[i] = min(dp[i - c] + 1 , dp[i]);
			}
		}
	}

	return dp[amt];
}

ll count_coins_TD(vcll coins, vcll a, ll amt, ll index) {
	if (amt < 0 or index == coins.size()) {
		return INT_MAX;
	}

	if (amt == 0) {
		return 0;
	}

	if (a[amt] != -1) {
		return a[amt];
	}

	return a[amt] = min(1 + count_coins_TD(coins, a, amt - coins[index], index) , count_coins_TD(coins , a, amt, index + 1));

}

ll count_coins(vcll coins, ll amt , ll index) {
	if (amt < 0 or index == coins.size()) {
		return INT_MAX;
	}

	if (amt == 0) {
		return 0;
	}

	return min(1 + count_coins(coins, amt - coins[index] , index) , count_coins(coins, amt, index + 1));
}

void solve() {
	vcll coins{1, 3, 4};
	ll amount = 6;
	vcll dp(amount + 1 , -1);
	// cout << count_coins(coins , amount , 0) << newl;
	// cout << count_coins_TD(coins, dp, amount, 0) << newl;
	// cout << cnt;
	cout << count_coins_BU(coins , amount);
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
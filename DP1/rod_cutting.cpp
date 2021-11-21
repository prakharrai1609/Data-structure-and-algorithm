
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

ll max_profit_bu(vcll costs) {
	ll length = costs.size();
	vcll dp(length + 1 , -1);
	dp[0] = 0;
	for (ll len = 1; len <= length; len++) {
		for (ll i = 0; i < len; i++) {
			ll cut = i + 1;
			dp[len] = max(dp[len] , dp[len - cut] + costs[i]);
		}
	}

	return dp[length];

}

ll max_profit_memo(vcll costs, ll length, vcll dp) {
	if (length ==  0) {
		return 0;
	}

	if (dp[length] != -1) {
		return dp[length];
	}

	ll ans = INT_MIN;

	for (ll i = 0; i < length; i++) { // here we are looping till the length of the rod and not on the size of the cost array hence we dont have to check for negiative value of the rod .
		// ll temp = costs[i] + max_profit(costs, length - (i + 1));

		ll cut = i + 1;
		ll temp = costs[i] + max_profit_memo(costs, length - cut, dp);
		ans = max(ans , temp);
	}

	return dp[length] = ans;
}

ll max_profit_1(vcll costs, ll length) {
	if (length ==  0) {
		return 0;
	}

	ll ans = INT_MIN;

	for (ll i = 0; i < length; i++) { // here we are looping till the length of the rod and not on the size of the cost array hence we dont have to check for negiative value of the rod .
		// ll temp = costs[i] + max_profit(costs, length - (i + 1));

		ll cut = i + 1;
		ll temp = costs[i] + max_profit_1(costs, length - cut);
		ans = max(ans , temp);
	}

	return ans;
}

ll max_profit(vcll costs, ll length, ll index) {

	if (length == 0) {
		return 0;
	}

	if (index == costs.size() or length < 0) {
		return INT_MIN;
	}

	return max(max_profit(costs, length - (index + 1), index) + costs[index], max_profit(costs , length, index + 1));
}

void solve() {
	vcll costs{3, 5, 8, 9, 10, 17, 17, 20};
	ll length = costs.size();
	// cout << max_profit(costs, length, 0);
	cout << max_profit_1(costs, length) << newl;
	vcll dp(length + 1, -1);
	cout << max_profit_memo(costs, length , dp) << newl;
	cout << max_profit_bu(costs);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve();
}
/* This is my journey and i shall endure the work to reach the top .*/
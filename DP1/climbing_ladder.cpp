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

ll climbSteps_rec(ll n) {
	if (n < 0) {
		return 0;
	}

	if (n == 0) {
		return 1;
	}

	return climbSteps_rec(n - 1) + climbSteps_rec(n - 2) + climbSteps_rec(n - 3);
}

ll climbSteps_memo(ll n, ll *a) {
	if (n < 0) {
		return 0;
	}

	if (n == 0)
		return 1;

	if (a[n] != -1)
		return a[n];

	return a[n] = climbSteps_memo(n - 1 , a) + climbSteps_memo(n - 2 , a) + climbSteps_memo(n - 3 , a);
}

ll climbSteps_bu(ll n) {
	vcll a(n + 1 , 0);
	a[0] = 1;

	for (ll i = 1; i <= n; i++) {
		if (i - 1 >= 0) {
			a[i] += a[i - 1];
		}

		if (i - 2 >= 0) {
			a[i] += a[i - 2];
		}

		if (i - 3 >= 0) {
			a[i] += a[i - 3];
		}
	}

	return a[n];
}

ll climb_steps_optimised_BU(ll n, ll k) {
	vcll a(n + 1, 0);
	a[0] = a[1] = 1;

	for (ll i = 2; i <= k; i++) {
		a[i] = 2 * a[i - 1];
	}

	for (ll i = k + 1; i <= n; i++) {
		a[i] = 2 * a[i - 1] - a[i - k - 1];
	}

	return a[n];
}

void solve() {

	ll n = 4;
	// cout << climbSteps_rec(n);
	ll a[n + 1];
	memset(a , -1 , sizeof(a));
	// cout << climbSteps_memo(n , a);
	// cout << climbSteps_bu(5);
	cout << climb_steps_optimised_BU(5 , 3);
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
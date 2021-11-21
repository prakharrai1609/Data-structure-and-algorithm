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

ll bsearch(ll s) {
	ll start = 1;
	ll end = s;
	ll ans;

	while (start <= end) {
		ll mid = (start + end) / 2;

		if (mid * mid <= s) {
			ans = mid;
			start = mid + 1;
		}

		if (mid * mid > s) {
			end = mid - 1;
		}
	}

	return ans;
}

void solve() {
	ll n , p; // n -> no of which root is required , p -> decimal place till which root is needed
	cin >> n >> p;

	// lets find the base using binary search
	ll base = bsearch(n);

	// now we'll find the decimal places using linear search

	ld num = base;
	ld inc = 0.1;

	for (ll i = 1; i <= p; i++) {
		for (ll j = 1; j < 10; j++) {
			ld check = num + inc * j;
			if (check * check <= n) {
				num = check;
			} else {
				break;
			}
		}
		inc /= 10.0;
	}

	cout << num;
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
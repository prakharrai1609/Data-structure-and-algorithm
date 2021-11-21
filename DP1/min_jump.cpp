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

void myApproach() {
	vcll a{3, 4, 2, 1, 2, 3, 7, 1, 1, 3};
	ll n = a.size();

	ll max_reach_last , max_reach_curr;
	ll steps = 0;

	max_reach_last = 0;
	max_reach_curr = a[0];

	while (max_reach_curr < n - 1) {
		ll mx = max_reach_curr;

		for (ll i = max_reach_last + 1; i <= max_reach_curr; i++) {
			if (i + a[i] > mx) {
				mx = i + a[i];
			}
		}

		max_reach_last = max_reach_curr;
		max_reach_curr = mx;
		steps++;
	}

	cout << steps + 1;

}

ll min_jumps(vcll a, ll n, vcll &dp, ll i) {
	if (i == n - 1) {
		return 0;
	}

	if (i >= n) {
		return INT_MAX;
	}

	if (dp[i] != 0) {
		return dp[i];
	}

	ll steps = INT_MAX;
	ll max_jump = a[i];

	for (ll jump = 1; jump <= max_jump; jump++) {
		ll next_cell = i + jump;
		ll sub_problem = min_jumps(a, n, dp, next_cell);

		if (sub_problem != INT_MAX) {
			steps = min(steps , sub_problem + 1);
		}
	}

	return dp[i] = steps;
}

void solve() {
	vcll a{3, 4, 2, 1, 2, 3, 7, 1, 1, 3};
	ll n = a.size();

	vcll dp(n , 0);
	cout << min_jumps(a, n, dp, 0);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve();
}
/* This is my journey and i shall endure the work to reach the top .*/
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

bool canPlaceBirds(ll n, ll b, vcll nests, ll sep) {
	ll birds = 1;
	ll location = nests[0];

	for (ll i = 0; i < n; i++) {
		ll current_location = nests[i];
		if (current_location - location >= sep) {
			birds++;
			location = current_location;

			if (birds == b) {
				return true;
			}
		}
	}

	return false;

}

void solve() {
	ll n , b;
	cin >> n >> b;
	vcll nests(n);
	lol(i, 0, n) cin >> nests[i];


	sort(all(nests));
	// MINIMUM DISTANCE WHERE BIRDS CAN BE PLACED
	ll s = 0;
	// MAXIMUM DISTANCE WHERE BIRDS CAN BE PLACED
	ll e = nests[n - 1] - nests[0];
	ll ans = -1;

	while (s <= e) {
		ll mid = (s + e) / 2;
		bool canPlace = canPlaceBirds(n , b , nests, mid);

		if (canPlace) {
			ans = mid;
			s = mid + 1;
		} else {
			e = mid - 1;
		}

	}

	cout << ans;

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
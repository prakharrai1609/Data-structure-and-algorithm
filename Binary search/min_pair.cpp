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

void init() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

/* 	My approach  */

// ll count_min_pair(vcll a, vcll b) {
// 	ll n = a.size();
// 	ll m = b.size();

// 	vector<pair<ll , ll>> c;

// 	lol(i, 0, n) {
// 		c.push_back({a[i] , 1});
// 	}

// 	lol(i, 0, m) {
// 		c.push_back({b[i] , 2});
// 	}

// 	sort(c.begin() , c.end());

// 	ll prev = c[0].second;
// 	ll ans = INT_MAX;

// 	for (ll i = 1; i <= (n + m - 2); i++) {
// 		if (prev != c[i].second) {
// 			ans = min(ans , abs(c[i].first - c[i - 1].first));
// 		}
// 		prev = c[i].second;
// 	}

// 	return ans;
// }

void count_min_pair(vcll a , vcll b) {
	sort(all(b));
	ll diff = INT_MAX;
	ll p1 , p2;

	for (int x : a) {
		ll lb = LB(b , x);
		if (lb < a.size() and b[lb] - x < diff) {
			diff = b[lb] - x;
			p1 = x;
			p2 = b[lb];
		}

		if (lb >= 1 and x - b[lb - 1] < diff) {
			diff = x - b[lb - 1];
			p1 = b[lb - 1];
			p2 = x;
		}
	}

	cout << p1 << ' ' << p2;
}


int main() {
	init();
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	ll n , m;
	cin >> n >> m;

	vcll a1(n);
	vcll a2(m);

	lol(i, 0, n) cin >> a1[i];
	lol(i, 0, m) cin >> a2[i];

	// cout << count_min_pair(a1 , a2);

	count_min_pair(a1 , a2);

}
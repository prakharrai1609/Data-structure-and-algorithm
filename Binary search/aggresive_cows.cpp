/*    Author : Prakhar Rai    */
#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lld long double
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

void init() {
#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#define debug(x) cerr << #x <<" "; _print(x); cerr << newl;
#else
#define debug(x);
#endif
}

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(lld t) {cerr << t;}
void _print(double t) {cerr << t;}
void _print(ull t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.ff); cerr << ","; _print(p.ss); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}
// void _print(pbds v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

/*-----------------------------------DEBUGGER ENDS HERE---------------------------------------*/

bool can(vcll a, ll mid , ll N) {
	ll c = 1;
	ll current_location = a[0];
	ll n = a.size();

	for (ll i = 0; i < n; i++) {
		if (a[i] - current_location >= mid) {
			c++;
			if (c == N) {
				return true;
			}
			current_location = a[i];
		}
	}

	return false;

}


void solve() {
	ll n , c;
	cin >> n >> c;

	vcll a(n);
	lol(i, 0, n) cin >> a[i];

	sort(all(a));
	ll ans = 0;
	ll s = 0;
	ll e = a[n - 1] - a[0];

	debug(s);
	debug(e);

	while (s <= e) {
		ll mid = (s + e) / 2;

		if (can(a , mid , c)) {
			ans = max(ans , mid);
			s = mid + 1;
		} else {
			e = mid - 1;
		}

	}

	cout << ans << newl;

}

// FILE WITH TEST CASE




int main() {
	init();
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t; cin >> t;
	while (t--)
		solve();
}
/* This is my journey and i shall endure the work to reach the top .*/
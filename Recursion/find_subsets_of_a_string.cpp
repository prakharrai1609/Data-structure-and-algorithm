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

void print_substrings(string s, string ans, int index) {

	// base case
	if (index == s.length()) {
		cout << ans << endl;
		return;
	}

	// subproblem
	print_substrings(s , ans + s[index], index + 1);
	print_substrings(s , ans , index + 1);
}

void printStrings(string s, string e, set<string> &v, ll i) {
	if (i == s.length())
		return;

	v.insert(e);
	printStrings(s, e, v, i + 1);
	e += s[i];
	v.insert(e);
	printStrings(s, e, v, i + 1);

}

void solve() {
	string s;
	cin >> s;
	string e = "";
	set<string> v;
	ll i = 0;
	printStrings(s, e, v, i);

	for (auto x : v)
		cout << x << newl;

}

void subs(string s, string e) {
	// v.pb(e);
	if (s.empty()) {
		cout << e << newl;
		return;
	}
	cout << e << newl;
	subs(s.substr(1) , e + s[0]);
	subs(s.substr(1) , e);
}

void solve1() {
	string s;
	cin >> s;
	string e = "";
	subs(s , e);
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
	solve1();
}
/* This is my journey and i shall endure the work to reach the top .*/
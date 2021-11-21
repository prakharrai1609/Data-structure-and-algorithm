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

ll count_subsets(vcll a, ll sum, ll v, ll i) {
	if (v == sum)
		return 1;

	if (v > sum or i < 0)
		return 0;

	ll op1 = 0 , op2 = 0;
	if (a[i] + v <= sum) {
		op1 = count_subsets(a, sum, v + a[i], i - 1);
	}

	op2 = count_subsets(a, sum , v, i - 1);

	return op1 + op2;

}

int subsets(vector<int> a, int sum , int index) {

	//	Base Case

	if (sum == 0) {
		return 1;
	}

	if (index == a.size()) {
		return 0;
	}

	ll option1 , option2;
	// option1 = option2 = 0;
	option1 = 0;

	if (a[index] <= sum)
		option1 = subsets(a , sum - a[index] , index + 1);
	option2 = subsets(a , sum , index + 1);

	return option1 + option2;
}


ll count_subsets_better(vcll a, ll sum, ll i) {
	if (sum < 0)
		return 0;

	if (i == a.size()) {
		if (sum == 0)
			return 1;
		return 0;
	}

	ll include = count_subsets_better(a , sum - a[i] , i + 1);
	ll exclude = count_subsets_better(a , sum , i + 1);

	return include + exclude;
}

void solve() {
	vcll a = {1, 2, 3, 4, 5, 6};
	ll sum = 6;
	ll v = 0;

	// cout << count_subsets(a , sum, v, a.size() - 1);
	cout << count_subsets_better(a, sum , 0);
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
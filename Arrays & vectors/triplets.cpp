#include<bits/stdc++.h>
#define ll long long
#define vcll vector<ll>
using namespace std;

void init() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

/*
	Q. If we have an array , we need to find all the triplets such that their sum is the target sum
	A. 3 approches :
		1. Brute force
		2. Sort the array (NlogN) and for each element in the array do a 2 pointer (N * N)
*/

vector<vcll> findTriplets(vcll &a, ll sum) {
	vector<vcll> sol;
	for (ll i = 0; i < a.size() - 2; i++) {
		ll p1 , p2 , comparator;
		comparator = sum - a[i];
		p1 = i + 1 , p2 = a.size() - 1;

		while (p1 < p2) {
			if (a[p1] + a[p2] == comparator) {
				sol.push_back({a[i] , a[p1] , a[p2]});
				p1++;
				p2--;
			} else if (a[p1] + a[p2] > comparator) {
				p2--;
			} else {
				p1++;
			}
		}
	}

	return sol;
}

int main() {
	init();
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	ll n;
	cin >> n;
	vcll a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];
	ll target_sum; cin >> target_sum;

	sort(a.begin() , a.end());
	vector<vcll> sol = findTriplets(a , target_sum);
	for (auto x : sol) {
		for (auto i : x) {
			cout << i << ' ';
		} cout << endl;
	}
}
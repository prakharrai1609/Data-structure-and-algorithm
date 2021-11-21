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

ll UB(vcll a , ll n) {
	ll s = 0 , e = a.size() - 1;

	ll ans = -1;

	while (s <= e) {
		ll mid = (s + e) / 2;

		if (a[mid] == n) {
			ans = mid;
			s = mid + 1;
		}

		if (a[mid] > n) {
			e = mid - 1;
		}

		if (a[mid] < n) {
			s = mid + 1;
		}
	}

	return ans;
}

ll LB(vcll a , ll n) {
	ll s = 0 , e = a.size() - 1;

	ll ans = -1;

	while (s <= e) {
		ll mid = (s + e) / 2;

		if (a[mid] == n) {
			ans = mid;
			e = mid - 1;
		}

		if (a[mid] > n) {
			e = mid - 1;
		}

		if (a[mid] < n) {
			s = mid + 1;
		}
	}

	return ans;
}

int main() {
	init();
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	vcll a{0, 1, 1, 1, 1, 2, 2, 2, 3, 4, 4, 5, 10};
	ll l = LB(a , 100);

	cout << l << ' ';
	ll r = UB(a , 100);
	cout << r << ' ';

	cout << (r - l + 1);
}
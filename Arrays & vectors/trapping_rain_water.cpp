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

int rain(vcll h) {
	ll n = h.size();
	vcll left(n) , right(n);
	ll mx = h[0];
	left[0] = mx;

	/* WE CALCULATE THE HEIGHTS OF ALL THE ELEMENTS GREATER THAN CURRENT INDEX ON THE LEFT*/

	for (ll i = 1; i < n; i++) {
		if (h[i] > mx) {
			mx = h[i];
		}

		left[i] = mx;
	}

	/* WE CALCULATE THE HEIGHTS OF ALL THE ELEMENTS GREATER THAN CURRENT INDEX ON THE RIGHT*/

	mx = h[n - 1];
	right[n - 1] = mx;

	for (int i = n - 2; i >= 0; i--) {
		if (h[i] > mx) {
			mx = h[i];
		}

		right[i] = mx;
	}

	/* NOW WE COUT << MINIMUM OF LEFT GREATEST AND RIGHT GRATEST - HEIGHT OF CURRENT BLOCK*/

	mx = 0;
	int total_water = 0;
	for (ll i = 0; i < n; i++) {
		ll height = min(left[i] , right[i]) - h[i];
		mx = max (mx , height);
		total_water += height;
	}
	cout << total_water << endl;
	return mx;

}

int main() {
	init();
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	vcll heights(n);
	for (int i = 0; i < n; i++) cin >> heights[i];

	cout << rain(heights);

}
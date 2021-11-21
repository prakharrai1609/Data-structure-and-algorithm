#include<bits/stdc++.h>
#include<chrono>
#define ll long long
#define vcll vector<ll>
using namespace std;
using namespace std::chrono;

void init() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

/*
	My approach : works only for positive numbers

	auto start = high_resolution_clock::now();

	int n; cin >> n;
	vcll a(n);

	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	ll mx = *max_element(a.begin() , a.end());
	vcll lookup(mx + 1 , 0);

	for (auto x : a) {
		lookup[x]++;
	}

	ll cnt = 0 , mx1 = INT_MIN;
	for (ll i = 0; i < lookup.size(); i++) {
		if (lookup[i] == 1) {
			cnt++;
		} else {
			mx1 = max(mx1 , cnt);
			cnt = 0;
		}
	}

	cout << max(mx1 , cnt) << endl;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken by function: " << duration.count() << " microseconds" << endl;

*/


int main() {
	init();
	ios_base::sync_with_stdio(false); cin.tie(NULL);


	/* HASHING */

	int n; cin >> n;
	vcll a(n);
	unordered_set<int> u;
	map<int , int> m;
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
		u.insert(a[i]);
	}
	ll length = 0 , mx = -1;

	for (auto x : a) {
		// Lets check if x can start a band , for ex. if we have 0 in the set , 1 cannot start a band
		if (u.find(x - 1) != u.end()) {
			continue;
		}

		// If x can start a band we will go ahead and check the check the length of the band

		int temp = x;
		while (1) {
			if (u.find(temp) != u.end()) {
				length++;
				temp++;
			} else {
				break;
			}
		}

		mx = max(length , mx);
		length = 0;
	}

	cout << mx << endl;

}
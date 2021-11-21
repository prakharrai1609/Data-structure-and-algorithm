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
	Q. Given an array , find 2 numbers such that their sum is target_sum
	Input
	------
	Number of elements
	Array
	Target sum

	Sol. 1. Brute force ------------------------------- O(N^2)
		 2. Binary search------------------------------ O(NlogN)
		 3. Store values in a set (Unordered)---------- O(N)
		 4. 2 pointer

*/

int bsearch(vector<int> &a , int start, int end, int num) {
	while (start <= end) {
		int mid = (start + end) / 2;
		if (a[mid] == num) {
			return 1;
		}

		if (mid > num) {
			end = mid - 1;
			continue;
		}

		start = mid + 1;
	}

	return 0;
}

int main() {
	init();
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	int target_sum; cin >> target_sum;


	/*Binary search*/


	/*

		sort(a.begin() , a.end());
		for (ll i = 0; i < n; i++) {
			if (bsearch(a , 0 , n , target_sum - a[i])) {
				cout << a[i] << ' ' << target_sum - a[i];
				break;
			}
		}

		*/

	/* Hashing */

	/*

	unordered_set<int> u;
	for (auto it : a) {
		u.insert(it);
	}

	for (auto x : a) {
		if (x != target_sum - x) {
			if (u.find(target_sum - x) != u.end()) {
				cout << x << ' ' << target_sum - x;
				break;
			}
		} else {
			if (u.count(x) > 1) {
				cout << x << ' ' << x;
				break;
			}
		}
	}

	*/

}
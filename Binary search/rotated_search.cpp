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

ll bsearch(vcll a, ll key) {

	ll n = a.size();

	ll start = 0 , end = n - 1;

	while (start <= end) {
		ll mid = (start + end) / 2;

		if (a[mid] == key) {
			return mid;
		}

		/*	If we are on the first line which is rotated from back*/

		if (a[start] <= a[mid]) {

			if (a[mid] >= key and a[start] <= key) {
				end = mid - 1;
			} else {
				start = mid + 1;
			}

		}

		/*	If we are on second line which contains the samaller elements */

		else {

			if (a[mid] <= key and a[end] >= key) {
				start = mid + 1;
			} else {
				end = mid - 1;
			}

		}

	}

	return -1;
}

int main() {
	init();
	ios_base::sync_with_stdio(false); cin.tie(NULL);


	vcll a{7 , 8 , 9 , 10 , 1 , 2 , 3 , 4, 5, 6};

	ll num = 2;
	cout << bsearch(a , num);

}
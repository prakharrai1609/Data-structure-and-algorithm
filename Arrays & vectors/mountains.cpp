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
	Q. Find the number of elements in the highest peaks
	ex. 1 2 3 4 5 6 4 3 1 ---> 6 is peak , total numbers in the peak are
						6
					5 		4
				4 				3
			3						1
		2
	1

	<---------------- 9 ------------->

	so the peak has 9 elements

*/

int highest_mountain(vector<int> a) {
	int largest = 0;

	int n = a.size();

	// Check if a[i] is a peak or not
	for (int i = 1; i <= n - 2; ) {

		if (a[i] > a[i - 1] and a[i] > a[i + 1]) {
			int cnt = 1;
			int j = i;

			// check forward
			while (j >= 1 and a[j] > a[j - 1]) {
				cnt++;
				j--;
			}

			// check backwards
			while (i <= n - 2 and a[i] > a[i + 1]) {
				i++;
				cnt++;
			}

			largest = max(largest , cnt);
		} else {
			i++;
		}
	}
	return largest;
}

int main() {
	init();
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];

	cout << highest_mountain(a);

}
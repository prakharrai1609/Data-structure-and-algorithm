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


int min_swaps_myApproach(vcll a) {

	ll swaps = 0;
	ll n;
	n = a.size();

	vcll v = a;
	sort(v.begin() , v.end());

	map<ll , ll> correct_index , visited;
	for (ll i = 0; i < v.size(); i++) {
		correct_index[v[i]] = i;
	}

	for (ll i = 0; i < a.size(); i++) {

		if (!visited[a[i]]) {
			ll cycles = 0;
			visited[a[i]] = 1;
			ll address = correct_index[a[i]];

			cout << a[i] << " --> "; // to see the cycles

			while (!visited[a[address]]) {
				visited[a[address]] = 1;
				cycles++;

				cout << a[address] << " --> "; // to see the cycles

				address = correct_index[a[address]];
			}

			cout << endl; // to see the cycles

			swaps += cycles;

		}

	}

	return swaps;


}

int countMinSwaps(vcll arr) {

	// Know the actual positions of elements (sorting)
	//store the current indices
	int n = arr.size();
	pair<int, int> ap[n];
	for (int i = 0; i < n; i++) {
		ap[i].first = arr[i];
		ap[i].second = i;
	}

	//sorting
	sort(ap, ap + n);

	//build the main logic
	vector<bool> visited(n, false);

	int ans = 0;
	for (int i = 0; i < n; i++) {

		// if element is visited or element is in right postion
		int old_position = ap[i].second;
		if (visited[i] == true or old_position == i) {
			continue;
		}

		// visiting the element (index) for first time
		int node = i;
		int cycle = 0;

		while (!visited[node]) {
			visited[node] = true;
			int next_node = ap[node].second;
			node = next_node;
			cycle += 1;
		}
		ans += (cycle - 1);

	}

	return ans;

}


int main() {
	init();
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	ll n; cin >> n;
	vcll a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	// cout << min_swaps(a);
	cout << countMinSwaps(a);

}
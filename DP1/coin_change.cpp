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

ll coin_change(ll den[], ll amt, ll n) {
	if (amt == 0)
		return 1;
	if (n == 0)
		return 0;
	if (amt < 0)
		return 0;

	ll fs = coin_change(den, amt - den[0], n);
	ll sc = coin_change(den + 1, amt, n - 1);

	return fs + sc;
}


ll coin_change_memoised(ll den[], ll amt, ll n, ll *output) {
	if (amt == 0)
		return 1;
	if (n == 0)
		return 0;
	if (amt < 0)
		return 0;

	if (output[n][amt] > -1)
		return output[amt][n];

	ll fs = coin_change_memoised(den, amt - den[0], n, output);
	ll sc = coin_change_memoised(den + 1, amt, n - 1, output);

	return output[amt][n] = fs + sc;
}


int main() {
	init();
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	ll arr[] = {1 , 2 , 5};
	ll amt = 4;
	ll n = sizeof(arr) / sizeof(arr[0]);
	cout << coin_change(arr , amt , n) << endl;
	ll output[n + 1][amt + 1];
	memset(output , -1 , sizeof(output));
	cout << coin_change_memoised(arr , 4 , n , output) << endl;
}
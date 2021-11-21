/*
	Find the combinations of the coins used to make a sum s
	Method 1 > 2d dp
	Method 2 > make a 1d dp (tricky but awesome)
*/
#include<bits/stdc++.h>
#define ll long long
#define vcll vector<ll>
#define newl "\n"
#define lol(i,a,b) for(ll i = a; i < b; i++)
using namespace std;

ll coinw(ll n, vcll coins) {
	vector<ll> dp(n + 1, 0);
	dp[0] = 1;
	for (int coin : coins) {
		for (int i = 1; i <= n; i++) {
			if (i >= coin) {
				dp[i] += dp[i - coin];
			}
		}
	}

	for (int i : dp) {
		cout << i << ", ";
	} cout << newl;

	return dp[n];

}

void solve() {
	vcll coin{1, 2, 3};

	cout << coinw(4, coin);

}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve();
}
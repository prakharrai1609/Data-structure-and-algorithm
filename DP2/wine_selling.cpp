#include<bits/stdc++.h>
#define ll long long
#define vcll vector<ll>
using namespace std;

void print(vector<vcll> &dp) {
	for (ll i = 0; i < 5; i++) {
		for (ll j = 0; j < 5; j++) {
			cout << dp[i][j] << ' ';
		} cout << endl;
	}
}

ll costTD(vcll prices, ll start, ll end, ll year, vector<vcll> &dp) {

	if (start > end) {
		return 0;
	}

	if (dp[start][end] != 0) {
		return dp[start][end];
	}

	ll op1 = year * prices[start] + costTD(prices, start + 1, end, year + 1, dp);
	ll op2 = year * prices[end] + costTD(prices, start, end - 1, year + 1, dp);

	return dp[start][end] = max(op1, op2);
}

ll costBU(vcll prices) {
	ll n = prices.size();
	vector<vcll> dp((n + 1) , vcll ((n + 1) , 0));

	// Initialising the matrix diagonal

	for (ll i = n - 1; i >= 0; i--) {
		for (ll j = 0; j < n; j++) {

			if (i == j) {
				dp[i][j] = prices[i] * n;
			}

			if (i < j) {
				ll y = n - (j - i);
				ll left = prices[i] * y + dp[i + 1][j];
				ll right = prices[j] * y + dp[i][j - 1];

				dp[i][j] = max(left, right);
			}
		}
	}

	/*
		10 	23 	43 	45 	50

		0  	15 	37 	40 	48

		0  	0  	25 	29 	41

		0  	0  	0  	5  	24

		0  	0  	0  	0  	20

	*/


	// print(dp);

	return dp[0][n - 1];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	vcll prices{2, 3, 5, 1, 4};
	vector<vcll> dp(6 , vcll (5 , 0));
	cout << costTD(prices, 0, 4, 1, dp) << endl;
	// cout << costBU(prices);
	// print(dp);
}
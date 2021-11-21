
#include<bits/stdc++.h>
#define ll long long
#define vcll vector<ll>
using namespace std;
int cnt;

int count_tree_td(int n, vcll &dp) {
	if (n == 0 or n == 1)
		return 1;

	if (dp[n] != -1)
		return dp[n];

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int left = count_tree_td(i - 1, dp);
		int right = count_tree_td(n - i, dp);
		ans += (left * right);
	}

	return dp[n] = ans;
}

int count_treeBU(int N) {
	vcll dp(N + 1, 0);
	dp[0] = dp[1] = 1;

	for (int n = 2; n <= N; n++) {
		for (int i = 1; i <= n; i++) {
			dp[n] += (dp[n - i] * dp[i - 1]);
		}
	}

	return dp[N];
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	int n; cin >> n;
	vcll dp(n + 1 , -1);
	cout << count_treeBU(n);

}
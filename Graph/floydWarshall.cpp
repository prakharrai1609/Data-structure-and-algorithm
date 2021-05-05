#include<bits/stdc++.h>
#define ll long long
using namespace std;

void floydWarshall(vector<vector<ll>> &v , ll n) {
	vector<vector<ll>> dist(v);
	for (ll k = 0; k < n; k++) {
		for (ll i = 0; i < n; i++) {
			for (ll j = 0; j < n; j++) {
				if (dist[i][k] + dist[k][j] < dist[i][j])
					dist[i][j] = dist[i][k] + dist[k][j];
			}
		}
	}
	for (ll i = 0; i < n; i++) {
		for (ll j = 0; j < n; j++) {
			cout << dist[i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
#ifndef ONLINE_JUDGGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n = 4;
	vector<vector<ll>> v = {{0, INT_MAX, -2, INT_MAX},
		{4, 0, 3, INT_MAX},
		{INT_MAX, INT_MAX, 0, 2} ,
		{INT_MAX, -1, INT_MAX, 0}
	};

	floydWarshall(v, n);

}
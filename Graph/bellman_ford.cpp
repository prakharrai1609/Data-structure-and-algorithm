#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*	WE ARE CODING BELLMAN FORD ALGORITHM , WE NEED AN EDGE LIST IMPLIMENTATION OF GRAPH  */
/*  WE CHECK FOR A SMALLER EDGE (V-1) TIMES AND UPDATE LIST OF EDGES  */
/*  FINALLY WE CHECK IF WE ARE NOT IN A INFINITELY RUNNING NEGATIVE WEIGHT CYCLE  */

vector<ll> bellman_ford(ll src, vector<vector<ll>> &edges, ll n) {

	vector<ll> dist(n + 1, INT_MAX);
	dist[src] = 0;
	for (ll i = 0; i < n; i++) {

		for (auto edge : edges) {
			ll u = edge[0];
			ll v = edge[1];
			ll w = edge[2];

			if (dist[u] != INT_MAX and dist[u] + w < dist[v]) {
				dist[v] = dist[u] + w;
			}
		}
	}

	for (auto edge : edges) {
		ll u = edge[0];
		ll v = edge[1];
		ll w = edge[2];

		if (dist[u] != INT_MAX and dist[u] + w < dist[v]) {
			cout << "Negative edge cycle!";
			exit(0);
		}
	}

	return dist;
}

int main() {
#ifndef ONLINE_JUDGGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	vector<vector<ll>> edges;
	ll n, m;
	cin >> n >> m;

	for (ll i = 0; i < m; i++) {
		ll v, u, w;
		cin >> u >> v >> w;
		edges.push_back({u, v, w});
	}


	vector<ll> ans = bellman_ford(1, edges, n);
	for (ll i = 1; i <= n; i++) {
		cout << 1 << "--> " << i << "  : " << ans[i] << endl;
	}
}
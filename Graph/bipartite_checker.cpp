#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll dfsT(vector<ll> graph[], ll * visited, ll src, ll color, ll parent) {

	visited[src] = color;
	for (auto nbr : graph[src]) {
		if (!visited[nbr]) {
			ll check_cycle = dfsT(graph, visited, nbr, 3 - color, src);
			if (!check_cycle)
				return 0;
		} else if (parent != nbr and color == visited[nbr]) {
			return 0;
		}
	}

	return 1;
}

ll dfs(vector<ll> graph[], ll n) {
	ll visited[n] = {0};
	ll color = 1;
	ll parent = -1;
	return dfsT(graph, visited, 0, color, parent);
}

int main()
{
#ifndef ONLINE_JUDGGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	cin >> n >> m;
	vector<ll> graph[n];

	while (m--) {
		ll x, y;
		cin >> x >> y;

		graph[x].push_back(y);
		graph[y].push_back(x);
	}

	if (dfs(graph, n))
		cout << "Bipartite graph";
	else
		cout << "Not a bipartite garph";

	return 0;
}
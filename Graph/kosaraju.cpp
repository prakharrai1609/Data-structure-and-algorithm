#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*	THIS ALGORITHM IS USED TO FIND THE STRONGLY CONNECTED COMPONENTS IN A GRAPH*/

void dfs(vector<ll> graph[], ll i, ll *visited, vector<ll> &stack) {
	visited[i] = 1;

	for (auto nbr : graph[i]) {
		if (!visited[nbr])
			dfs(graph, nbr, visited, stack);
	}

	stack.push_back(i);
}

void dfs2(vector<ll> rev_graph[], ll i, ll *visited) {
	visited[i] = 1;
	cout << i << ' ';
	for (auto nbr : rev_graph[i]) {
		if (!visited[nbr])
			dfs2(rev_graph, nbr, visited);
	}
}

void solve(vector<ll> graph[], vector<ll> rev_graph[], ll n) {
	ll visited[n];
	memset(visited, 0, sizeof(visited));
	vector<ll> stack;

	for (ll i = 0; i < n; i++) {
		if (!visited[i])
			dfs(graph, i, visited, stack);
	}

	memset(visited, 0, sizeof(visited));

	ll num = 1;
	for (ll i = stack.size() - 1; i >= 0; i--) {
		if (!visited[stack[i]]) {
			cout << "Connected component " << num++ << " -->  ";
			dfs2(rev_graph, stack[i], visited);
			cout << endl;
		}
	}

}

int main() {
#ifndef ONLINE_JUDGGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll n, m;
	cin >> n >> m;

	vector<ll> graph[n];
	vector<ll> rev_graph[n];

	while (m--) {
		ll x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		rev_graph[y].push_back(x);
	}

	solve(graph, rev_graph, n);

	// for (ll i = 0; i < n; i++) {
	// 	cout << i << "--> ";
	// 	for (auto x : graph[i]) {
	// 		cout << x << ' ';
	// 	}
	// 	cout << endl;
	// }
}
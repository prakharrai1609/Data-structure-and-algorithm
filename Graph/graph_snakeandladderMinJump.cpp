#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Graph {
	map<ll, list<ll>> m;
public:
	void add(ll x, ll y) {
		m[x].push_back(y);
		//m[y].push_back(x);
	}

	void bfs(ll src, ll dest) {
		map<ll, ll> dist;
		queue<ll> q;
		q.push(src);

		for (auto x : m) {
			dist[x.first] = INT_MAX;
		}
		dist[src] = 0;

		while (!q.empty()) {
			ll n = q.front();
			q.pop();

			for (auto x : m[n]) {
				if (dist[x] == INT_MAX) {
					dist[x] = dist[n] + 1;
					q.push(x);
				}
			}
		}

		// for (auto x : dist) {
		// 	cout << x.first << '\t' << x.second << endl;
		// }

		cout << dist[dest];

	}


};

int main()
{
#ifndef ONLINE_JUDGGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Graph g;
	ll board[50] = {0};
	board[2] = 13;
	board[5] = 2;
	board[9] = 18;
	board[18] = 11;
	board[17] = -13;
	board[20] = -14;
	board[24] = -8;
	board[25] = 10;
	board[32] = -2;
	board[34] = -22;

	for (ll i = 0; i <= 36; i++) {
		for (ll j = 1; j <= 6; j++) {
			ll e = i + j + board[i + j];
			if (e <= 36)
				g.add(i, e);
		}
	}

	g.add(36, 36);

	g.bfs(0, 36);
	//g.print();
}
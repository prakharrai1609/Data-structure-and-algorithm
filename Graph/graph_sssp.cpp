#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Graph {
	map<ll , list<ll>> l;
public:
	void add(ll x, ll y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void bfs(ll src) {

		queue<ll> q;
		q.push(src);

		// ll v[100] = {0};
		// v[src] = 1;

		map<ll, ll> m; //map that stores the distance
		for (auto nodes : l)
			m[nodes.first] = INT_MAX;
		m[src] = 0;

		while (!q.empty()) {
			ll n = q.front();
			q.pop();
			for (auto x : l[n]) {
				if (m[x] == INT_MAX) {
					m[x] = m[n] + 1;
					q.push(x);
					//v[x] = 1;
					//m[x] = level;
				}

			}

		}

		for (auto x : m) {
			cout << "Dist from " << src << " to " << x.first << " is " << x.second << endl;
		}

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
	g.add(0, 1);
	g.add(1, 2);
	g.add(0, 3);
	g.add(1, 3);
	g.add(2, 3);
	g.add(3, 4);
	g.add(4, 5);
	g.add(0, 6);
	g.bfs(0);

}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Graph {
	vector<pair<ll, ll> > *l;
	ll V;

public:

	Graph(ll V) {
		this->V = V;
		l = new vector<pair<ll, ll>>[V];
	}

	void add(ll x, ll y, ll w) {
		l[x].push_back(make_pair(y, w));
		l[y].push_back(make_pair(x, w));
	}

	void print() {
		for (ll i = 0; i < V; i++) {
			cout << i << "--> ";
			for (auto nbr : l[i]) {
				cout << '(' << nbr.first << ':' << nbr.second << ')' << "--> ";
			}
			cout << '\n';
		}
	}

	int prim_mst() {
		priority_queue <pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> q;

		ll ans = 0;
		ll *visited = new ll[V] {0};
		q.push({0, 0}); // weight , vertex

		while (!q.empty()) {
			auto best = q.top();
			q.pop();

			auto to = best.first;
			auto w = best.second;

			if (visited[to])
				continue;

			ans += w;
			visited[to] = 1;

			for (auto nbr : l[to]) {
				if (!visited[nbr.first])
					q.push({nbr.first , nbr.second});
			}
		}

		return ans;
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

	Graph g(4);
	g.add(0, 1, 1);
	g.add(0, 2, 2);
	g.add(0, 3, 2);
	g.add(1, 2, 2);
	g.add(1, 3, 2);
	g.add(2, 3, 3);
	// g.print();

	cout << g.prim_mst();

}
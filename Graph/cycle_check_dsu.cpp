#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Graph {
	ll V;
	list<pair<ll, ll>> l;
public:

	Graph(ll V) {
		this->V = V;
	}

	void add(ll x, ll y) {
		l.push_back(make_pair(x, y));
	}

	int findSet(ll x, ll *parent) {
		if (parent[x] == -1)
			return x;

		return findSet(parent[x], parent);
	}

	void unionSet(ll x, ll y, ll *parent) {
		ll s1 = findSet(x, parent);
		ll s2 = findSet(y, parent);

		if (s1 != s2)
			parent[s2] = s1;
	}

	bool check_cycle() {
		ll *parent = new ll[V];
		for (ll i = 0; i < V; i++)
			parent[i] = -1;

		for (auto edge : l) {
			ll s1 = findSet(edge.first, parent);
			ll s2 = findSet(edge.second, parent);

			if (s1 != s2) {
				unionSet(edge.first, edge.second, parent);
			} else {
				return true;
			}
		}

		delete [] parent;
		return false;
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
	g.add(0, 1);
	g.add(1, 2);
	g.add(3, 2);
	// g.add(3, 0);

	cout << g.check_cycle();


}
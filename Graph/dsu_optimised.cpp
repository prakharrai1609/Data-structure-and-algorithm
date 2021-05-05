#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Graph {
	list<pair<ll, ll>> l;
	ll V;
public:

	Graph(ll V) {
		this->V = V;
	}

	void add(ll x, ll y) {
		l.push_back(make_pair(x, y));
	}

	ll find(ll i, ll *parent) {

		if (parent[i] == -1)
			return i;
		return parent[i] = find(parent[i], parent);
	}

	void unionSet(ll x, ll y, ll *parent, ll *rank) {

		ll s1 = find(x, parent);
		ll s2 = find(y, parent);

		if (s1 != s2) {
			if (rank[s1] > rank[s2]) {
				rank[s1] += rank[s2];
				parent[s2] = s1;
			} else {
				rank[s2] += rank[s1];
				parent[s1] = s2;
			}
		}
	}

	bool check_cycle() {
		ll *parent = new ll[V];
		ll *rank = new ll[V];

		for (ll i = 0; i < V; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}

		for (auto pair : l) {
			ll s1 = find(pair.first , parent);
			ll s2 = find(pair.second , parent);

			if (s1 != s2) {
				unionSet(s1, s2, parent, rank);
			} else {
				return true;
			}
		}

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

	Graph g(5);
	g.add(0, 1);
	g.add(1, 2);
	g.add(2, 3);
	g.add(3, 4);
	g.add(4, 0);
	cout << g.check_cycle();


}
#include<bits/stdc++.h>
#define ll long long
using namespace std;

class DSU {
	ll V;
	ll *parent;
	ll *rank;

public:

	DSU(ll V) {
		this->V = V;
		parent = new ll[V];
		rank = new ll[V];
		for (ll i = 0; i < V; i++) {
			parent[i] = -1;
			rank[i] = 1;
		}
	}

	ll find(ll i) {
		if (parent[i] == -1)
			return i;

		return parent[i] = find(parent[i]);
	}

	void unite(ll x, ll y) {
		ll s1 = find(x);
		ll s2 = find(y);

		if (s1 != s2) {
			if (rank[s2] > rank[s1]) {
				rank[s2] += rank[s1];
				parent[s1] = s2;
			} else {
				rank[s1] += rank[s2];
				parent[s2] = s1;
			}
		}
	}
};

class Graph {
	ll V;
	vector<vector<ll>> v;

public:

	Graph(ll V) {
		this->V = V;
	}

	void add(ll x, ll y, ll w) {
		v.push_back({w, x, y});
	}

	void print() {
		for (auto l : v) {
			for (auto vx : l) {
				cout << vx << ' ';
			}
			cout << endl;
		}
	}

	ll kruskals() {
		DSU s(V);
		ll ans = 0;
		sort(v.begin(), v.end());
		for (auto vc : v) {
			ll w = vc[0];
			ll x = vc[1];
			ll y = vc[2];


			ll s1 = s.find(x);
			ll s2 = s.find(y);

			if (s1 != s2) {
				s.unite(s1, s2);
				ans += w;
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
	g.add(0, 3, 2);
	g.add(1, 2, 3);
	g.add(1, 3, 4);
	g.add(2, 3, 4);
	g.add(0, 1, 1);
	g.add(0, 2, 2);


	cout << g.kruskals();

}
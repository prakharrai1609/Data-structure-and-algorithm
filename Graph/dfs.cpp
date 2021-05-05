#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Graph {
	map<ll , list<ll>> l;
public:

	void add(ll x , ll y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void dfsT(ll src , map<ll, ll> &v) {
		cout << src << ' ';
		v[src] = 1;
		for (auto n : l[src]) {
			if (!v[n]) {
				dfsT(n, v);
			}

		}
	}

	void dfs(ll src) {
		map<ll, ll> v;
		for (auto x : l) {
			v[x.first] = 0;
		}

		dfsT(src, v);
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
	g.add(2, 3);
	g.add(3, 4);
	g.add(4, 5);
	g.add(3, 0);

	g.dfs(0);

}

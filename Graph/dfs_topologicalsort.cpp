#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Graph {
	map<ll, list<ll>> l;
public:
	void add(ll x, ll y) {
		l[x].push_back(y);
	}

	void dfsT(ll s , map<ll, ll> &v, list<ll> &store) {
		//cout << s << ' ';
		v[s] = 1;

		for (auto nbr : l[s]) {
			if (!v[nbr]) {
				dfsT(nbr, v, store);
			}
		}

		store.push_front(s);
	}

	void dfs(ll src) {
		list<ll> store;
		map<ll, ll> v;
		for (auto x : l)
			v[x.first] = 0;

		for (auto s : l) {
			if (!v[s.first])
				dfsT(s.first , v, store);
		}

		for (auto c : store) cout << c << ' ';
	}
};

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Graph g;
	g.add(1, 2);
	g.add(0, 2);
	g.add(2, 4);
	g.add(1, 3);
	g.add(3, 4);

	g.dfs(1);


}

#include<bits/stdc++.h>
#define ll long long
ll cnt;
using namespace std;

class Graph  {
	map<ll, list<ll>> l;
public:
	void add(ll x , ll y) {
		l[x].push_back(y);
		l[y].push_back(x);
	}

	void dfsT(ll src, map<ll, ll> &v) {
		cout << src << ' ';
		v[src] = 1;

		for (auto x : l[src]) {
			if (!v[x]) {
				dfsT(x, v);
			}
		}
	}

	void dfs(ll src) {
		map<ll, ll> m;
		for (auto x : l) {
			m[x.first] = 0;
		}
		for (auto x : m) {
			if (x.second == 0) {
				cout << endl << "Tree number : " << cnt + 1 << endl;
				dfsT(x.first, m);
				cnt++;
			}
		}

		cout << "\nNumber of connected components are " << cnt;

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
	g.add(3, 0);
	g.add(0, 4);

	g.add(5, 6);
	g.add(6, 7);

	g.add(8, 8);

	g.dfs(0);



}
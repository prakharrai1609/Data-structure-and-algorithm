#include<bits/stdc++.h>
#define ll long long
using namespace std;

class Graph {
	int V;
	list<ll> *l;
public:

	Graph(int V) {
		this->V = V;
		l = new list<ll>[V];
	}

	void add(ll src, ll dest) {
		l[src].push_back(dest);
		l[dest].push_back(src);
	}

	void print() {
		for (ll i = 0; i < V; i++) {
			cout << i << "-> ";
			for (auto nbr : l[i]) {
				cout << nbr << "-> ";
			}
			cout << endl;
		}
	}

	// DEPTH FIRST SEARCH

	void dfsHelper(ll src , map<ll, ll> &v) {
		cout << src << ' ';
		v[src] = 1;
		for (auto nbr : l[src]) {
			if (!v[nbr]) {
				dfsHelper(nbr, v);
			}
		}
	}

	void dfs(ll src) {
		map<ll, ll> visited;
		dfsHelper(src, visited);
	}

	// BREATH FIRST SEARCH

	void bfs(ll src) {
		map<ll, ll> visited;
		queue<ll> q;
		ll temp;

		q.push(src);
		visited[src] = 1;

		while (!q.empty()) {
			temp = q.front();
			q.pop();
			cout << temp << ' ';

			for (auto nbr : l[temp]) {
				if (!visited[nbr]) {
					q.push(nbr);
					visited[nbr] = 1;
				}
			}
		}
	}

	//SINGLE SOURCE SHORTEST PATH ALGORITHM

	void sssp(ll src) {
		map<ll, ll> dist;
		for (ll i = 0; i < V; i++) {
			dist[i] = INT_MAX;
		}
		queue<ll> q;
		q.push(src);
		dist[src] = 0;
		ll temp;

		while (!q.empty()) {
			temp = q.front();
			q.pop();

			for (auto nbr : l[temp]) {
				if (dist[nbr] == INT_MAX) {
					q.push(nbr);
					dist[nbr] = dist[temp] + 1;
				}
			}
		}

		for (auto x : dist) {
			cout << "Dist of " << src << " to " << x.first << " is " << x.second << endl;
		}

	}

	// CONNNECTED COMPONENTS

	void dfsHelper_cc(ll src , map<ll , ll> &v) {
		cout << src << ' ';
		v[src] = 1;

		for (auto nbr : l[src]) {
			if (!v[nbr])
				dfsHelper_cc(nbr, v);
		}
	}

	void dfs_cc() {
		map<ll , ll> visited;
		ll n = 0;
		for (ll i = 0; i < V; i++) {
			if (!visited[i]) {
				cout << "Connected component no : " << ++n << endl;
				dfsHelper_cc(i, visited);
				cout << endl;
			}
		}
	}


	// TOPOLOGICAL SORTING Dfs

	void toposort_dfs_helper(ll node, map<ll , ll> &v, list<ll> &li) {
		v[node] = 1;
		for (auto nbr : l[node]) {
			if (!v[nbr])
				toposort_dfs_helper(nbr, v, li);
		}

		li.push_front(node);
	}

	void toposort_dfs() {
		map<ll , ll> visited;
		list<ll> li;
		for (ll i = 0; i < V; i++) {
			if (!visited[i])
				toposort_dfs_helper(i, visited, li);
		}

		for (auto x : li) {
			cout << x << ' ';
		}
	}

	// TOPOLOGICAL SORTING Bfs

	void toposort_bfs() {

		ll indegree[V] = {0};
		for (ll i = 0; i < V; i++) {
			for (auto nbr : l[i]) {
				indegree[nbr]++;
			}
		}

		queue<ll> q;
		for (ll i = 0; i < V; i++) {
			if (!indegree[i]) {
				q.push(i);
			}
		}

		while (!q.empty()) {
			ll temp = q.front();
			q.pop();
			cout << temp << ' ';
			for (auto nbr : l[temp]) {
				indegree[nbr]--;
				if (!indegree[nbr]) {
					q.push(nbr);
				}
			}
		}


	}


	// CHECKING IF GRAPH IS A TREE

	bool is_tree(ll src) {
		ll parent[V];
		for (ll i = 0; i < V; i++) {
			parent[i] = i;
		}

		ll visited[V] = {0};
		queue<ll> q;
		q.push(src);
		visited[src] = 1;

		while (!q.empty()) {
			ll temp = q.front();
			q.pop();
			for (auto nbr : l[temp]) {
				if (!visited[nbr]) {
					parent[nbr] = temp;
					visited[nbr] = 1;
					q.push(nbr);
				} else if (visited[nbr]) {
					if (parent[temp] != nbr) {
						return false;
					}
				}
			}
		}

		return true;
	}


	// `````ANOTHER APPROACH - NOT WRONG BUT CONFUSING`````

	// bool check_cycle_dfs_helper(ll src, map<ll, ll> &v, ll *stack) {
	// 	stack[src] = 1;
	// 	v[src] = 1;
	// 	bool in_path;
	// 	for (auto nbr : l[src]) {
	// 		if (!stack[nbr]) {
	// 			in_path = check_cycle_dfs_helper(nbr, v, stack);
	// 			if (!in_path)
	// 				return false;
	// 		} else {
	// 			return false;
	// 		}
	// 	}
	// 	stack[src] = 0;
	// 	return true;
	// }

	// bool check_cycle_dfs() {
	// 	ll stack[V] = {0};
	// 	map<ll, ll> visited;
	// 	for (ll i = 0; i < V; i++) {
	// 		if (!visited[i]) {
	// 			if (!check_cycle_dfs_helper(i, visited, stack)) {
	// 				cout << "There is cycle";
	// 				return;
	// 			}
	// 		}
	// 	}
	// 	cout << "No cycle";
	// }

	// CHECKING CYCLE IN A DIRECTED GRAPH USING DFS

	bool check_cycle_dfs_helper_directed(ll src, map<ll , ll> &v, ll *stack) {
		stack[src] = 1;
		v[src] = 1;

		for (auto nbr : l[src]) {
			if (stack[nbr])
				return true;
			if (!v[nbr]) {
				bool is_path = check_cycle_dfs_helper_directed(nbr, v, stack);
				if (is_path)
					return true;
			}
		}

		stack[src] = 0;
		return false;
	} k

	bool check_cycle_dfs_directed() {
		map<ll , ll> visited;
		ll stack[V] = {0};
		bool cycle;

		for (ll src = 0; src < V; src++) {
			if (!visited[src]) {
				cycle = check_cycle_dfs_helper_directed(src, visited, stack);
				if (cycle)
					return true;
			}
		}

		return false;
	}


	// CHECK CYCLE IN AN UNDIRECTED GRAPH USING DFS


	bool check_cycle_dfs_helper_und(ll src, map<ll , ll> &v, ll parent) {
		v[src] = 1;
		for (auto nbr : l[src]) {
			if (!v[nbr]) {

				bool cycle = check_cycle_dfs_helper_und(nbr, v, src);
				if (cycle)
					return true;

			} else {
				if (nbr != parent)
					return true;
			}
		}
		return false;
	}

	bool check_cycle_dfs_und() {
		map<ll , ll> visited;
		ll parent = -1;
		return check_cycle_dfs_helper_und(0, visited, parent);
	}


};

int main() {
#ifndef ONLINE_JUDGGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Graph g(5);


	// -- set 1 of graph --

	g.add(1, 2);
	g.add(0, 2);
	g.add(1, 3);
	g.add(3, 4);
	g.add(4, 1);

	// -- set 2 of graph --

	// g.add(0, 2);
	// g.add(2, 3);
	// g.add(5, 2);
	// g.add(3, 5);
	// g.add(2, 1);
	// g.add(1, 4);
	// g.add(4, 5);

	// -- funtions in graph --

	if (g.check_cycle_dfs_und())
		cout << "Yes";
	else
		cout << "No";
	// if (g.check_cycle_dfs())
	// 	cout << "yes";
	// else
	// 	cout << "no";
	// if (g.is_tree(0))
	// 	cout << "Its a tree";
	// else
	// 	cout << "Its not a tree";
	// g.toposort_bfs();
	// g.toposort_dfs();
	// g.dfs_cc();
	// g.sssp(0);
	// g.bfs(0);
	// g.dfs(0);
	//g.print();

}
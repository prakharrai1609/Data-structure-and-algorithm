#include<bits/stdc++.h>
#define ll long long
using namespace std;

// DIJKSTRA IS AN ALGORITHM TO FIND SHORETEST PATH FROM 1 NODE TO ANOTHER IN A
// DIRECTED GRAPH .

class Graph {
	unordered_map <char , list<pair<char , ll>>>m;
public:

	void add(char x, char y, ll dist) {
		m[x].push_back(make_pair(y, dist));
		m[y].push_back(make_pair(x, dist));
	}

	void print() {
		for (auto x : m) {
			cout << x.first << "-> ";
			for (auto y : x.second) {
				cout << '(' << y.first << " : " << y.second << ')' << " -> ";
			}
			cout << endl;
		}
	}

	void dijkstra(char src) {
		unordered_map <char , ll> dist;	/* location , distance */
		set<pair<ll , char>> s;
		for (auto x : m) {
			dist[x.first] = INT_MAX;
		}
		dist[src] = 0;
		s.insert(make_pair(0, src));

		while (!s.empty()) {
			auto i = *(s.begin());
			ll d = i.first;
			char v = i.second;

			for (auto nbr : m[v]) {
				if (nbr.second + d < dist[nbr.first]) {
					char c = nbr.first;
					auto f = s.find(make_pair(dist[c], c));
					if (f != s.end()) {
						s.erase(f);
					}
					dist[nbr.first] = nbr.second + d;
					s.insert(make_pair(dist[c], c));
				}
			}

			s.erase(s.begin());
		}


		for (auto x : m) {
			cout << "Dist of " << src << " from " << x.first << " is " << dist[x.first] << endl;
		}
	}

};

int main() {
#ifndef ONLINE_JUDGGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Graph g;
	g.add('A' , 'B' , 10);
	g.add('A' , 'C' , 5);
	g.add('A' , 'E' , 9);
	g.add('D' , 'B' , 5);
	g.add('E' , 'B' , 15);
	g.add('D' , 'E' , 3);
	g.add('C' , 'E' , 3);
	g.print(); cout << endl;
	g.dijkstra('A');
}
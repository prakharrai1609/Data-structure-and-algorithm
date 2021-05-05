/*    Author : Prakhar Rai    */
#include<bits/stdc++.h>
#define ll long long
#define ld long double
#define LB(x,num) lower_bound(x.begin(),x.end(),num) - x.begin()
#define UB(x,num) upper_bound(x.begin(),x.end(),num) - x.begin()
#define BS(x,num) binary_search(x.begin(),x.end(),num)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define vci vector<int>
#define vcll vector<ll>
#define vcd vector<long double>
#define line(x) sort(x.begin(),x.end())
#define all(x) x.begin(),x.end()
#define newl "\n"
#define vc vector
#define loop(i,a,b) for(int i = a; i < b; i++)
#define lol(i,a,b) for(ll i = a; i < b; i++)
#define lod(i,a,b) for(ld i = 0; i < b; i++)
#define mod 1000000007
#define read(v,n) lol(i,0,n) {ll x; cin >> x; v.pb(x);}
#define run(a,x) for(auto x : a)
#define yes "YES"
#define no "NO"
ll cnt;
using namespace std;
// ll dp[10000000];
// memset(dp, -1, sizeof(dp));

template<typename T>
class Graph {
	map<T, list<T>> l;
public:
	void add(int x, int y) {
		l[x].pb(y);
		l[y].pb(x);
	}

	void bfs(T src) {
		queue<T> q;
		q.push(src);
		mkap<Tk, int> visited;
		visited[src] = 1;


		while (!q.empty()) {
			T node = q.front();
			q.pop();
			cout << node << " ";
			for (auto nbrs : l[node]) {
				if (!visited[nbrs]) {
					q.push(nbrs);
					visited[nbrs] = 1;
				}
			}
		}
	}

	void bfsDist(T src) {
		queue<T> q;
		map<T, int> dist;
		for (auto x : l) {
			dist[x.fs] = INT_MAX;
		}

		dist[src] = 0;
		q.push(src);

		while (!q.empty()) {
			T node = q.front();
			q.pop();
			for (auto x : l[node]) {
				if (dist[x] == INT_MAX) {
					q.push(x);
					dist[x] = dist[node] + 1;
				}
			}
		}

		for (auto x : dist) {
			cout << "Dist of " << x.fs << " from src is " << x.sc << '\n';
		}
	}

};

int main() {
#ifndef ONLINE_JUDGGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);

	Graph<int> g;
	g.add(0, 1);
	g.add(1, 2);
	g.add(0, 3);
	g.add(1, 3);
	g.add(2, 3);
	g.add(3, 4);
	g.add(4, 5);
	g.bfsDist(0);


}
/* This is my journey and i shall endure the work to reach the top .*/
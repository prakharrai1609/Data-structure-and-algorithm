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

class Graph {

private :
	int V;
	map<string, list<pair<string , int>>> l;

public :

	Graph(int v) {
		V = v;
	}

	void addEdge(string x, string y, bool check, int dist) {
		l[x].pb(mp(y, dist));
		if (check)
			l[y].pb(mp(x, dist));
	}

	void print() {
		for (auto x : l) {
			cout << x.fs << "-> ";
			for (auto c : x.sc) {
				cout << c.fs << ' ' << c.sc << ',';
			}
			cout << newl;
		}
	}

};

int main() {
#ifndef ONLINE_JUDGGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false); cin.tie(0);

	Graph g(4);
	g.addEdge("A", "D", false, 20);
	g.addEdge("A", "C" , true, 10);
	g.addEdge("A", "B", true, 10);
	g.addEdge("B", "D", true, 10);
	g.addEdge("C", "D", true, 10);

	g.print();
}
/* This is my journey and i shall endure the work to reach the top .*/
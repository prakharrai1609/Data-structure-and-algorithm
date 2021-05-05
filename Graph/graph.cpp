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
	list<int> *l;

public :

	Graph(int V) {
		this->V = V;
		l = new list<int>[V];
	}

	void addEdge(int x , int y) {
		l[x].pb(y);
		l[y].pb(x);
	}

	void print() {

		for (int i = 0; i < V; i++) {
			cout << "Vertex " << i << "-> ";
			for (auto x : l[i]) {
				cout << x << " ,";
			}
			cout << '\n';
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
	g.addEdge(0, 2);
	g.addEdge(0, 1);
	g.addEdge(1, 3);
	g.addEdge(2, 3);

	g.print();

}
/* This is my journey and i shall endure the work to reach the top .*/
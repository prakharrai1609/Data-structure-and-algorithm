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
// #define no "NO"
ll cnt;
using namespace std;
// ll dp[10000000];
// memset(dp, -1, sizeof(dp));

bool isSafe(vector<vector<ll>> mat, ll i, ll j, ll no, ll n) {
	for (ll k = 0; k < n; k++) {
		if (mat[i][k] == no || mat[k][j] == no) {
			return false;
		}
	}

	ll sx , sy;
	sx = (i / 3) * 3;
	sy = (j / 3) * 3;

	for (ll x = sx; x < sx + 3; x++) {
		for (ll y = sy; y < sy + 3; y++) {
			if (mat[x][y] == no) {
				return false;
			}
		}
	}

	return true;
}

bool solveSudoku(vector<vector<ll>> &mat, ll i, ll j, ll n) {

	// BASE CASE

	if (i == n) {
		for (ll x = 0; x < n; x++) {
			for (ll y = 0; y < n; y++) {
				cout << mat[x][y] << ' ';
			} cout << newl;
		}
		return true;
	}

	// SUB - PROBLEM

	if (j == n) {
		return solveSudoku(mat , i + 1 , 0, n);
	}

	if (mat[i][j] != 0) {
		return solveSudoku(mat, i , j + 1, n);
	}

	for (ll no = 1; no <= n; no++) {
		if (isSafe(mat, i, j, no, n)) {
			mat[i][j] = no;

			bool solveSubproblem = solveSudoku(mat, i, j + 1, n);
			if (solveSubproblem) {
				return true;
			}
		}
	}

	mat[i][j] = 0;
	return false;
}

void solve() {

	vector<vector<ll>> grid{
		{3, 0, 6, 5, 0, 8, 4, 0, 0},
		{5, 2, 0, 0, 0, 0, 0, 0, 0},
		{0, 8, 7, 0, 0, 0, 0, 3, 1},
		{0, 0, 3, 0, 1, 0, 0, 8, 0},
		{9, 0, 0, 8, 6, 3, 0, 0, 5},
		{0, 5, 0, 0, 9, 0, 6, 0, 0},
		{1, 3, 0, 0, 0, 0, 2, 5, 0},
		{0, 0, 0, 0, 0, 0, 0, 7, 4},
		{0, 0, 5, 2, 0, 6, 3, 0, 0} };


	if (!solveSudoku(grid , 0 , 0 , 9))
		cout << "No solution!";
}

// FILE WITH TEST CASE

void init() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

int main() {
	init();
	ios_base::sync_with_stdio(false); cin.tie(0);
	solve();
}
/* This is my journey and i shall endure the work to reach the top .*/
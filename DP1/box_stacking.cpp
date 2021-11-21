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

void print(vc<vcll> boxes) {
	for (auto x : boxes) {
		for (auto xx : x) {
			cout << xx << ' ';
		} cout << newl;
	} cout << newl;
}

bool height(vcll b1, vcll b2) {
	return b1[2] < b2[2];
}

ll max_height(vc<vcll> boxes) {
	ll n = boxes.size();
	sort(all(boxes) , height);
	vcll dp(n , 0);
	// print(boxes);

	lol(i, 0, n) {
		dp[i] = boxes[i][2];
		ll mx = INT_MIN;
		lol(j, 0, i) {
			if ((boxes[i][0] > boxes[j][0]) and (boxes[i][1] > boxes[j][1]) and (boxes[i][2] > boxes[j][2])) {
				mx = max(mx , dp[i] + dp[j]);
			}
		}
		dp[i] = max(mx , dp[i]);
	}

	// run(dp , i) cout << i << ' ';
	// cout << newl;
	return *max_element(all(dp));
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);

	vc<vcll> boxes{{2, 1, 2} , {3, 2, 3} , {2, 2, 8} , {2, 3, 4} , {2, 2, 1}, {4, 4, 5}};
	cout << max_height(boxes);

}

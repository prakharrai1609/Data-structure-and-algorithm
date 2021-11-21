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
vcll dp(1000 , -1);

ll myApproach(vcll a, ll n, ll index) {
    ll ans = a[index];
    // cnt++; --> just to check the difference how many times the function ran

    if (dp[index] != -1)
        return dp[index];

    lol(i, index + 2, n) {
        ans = max(ans , a[index] + myApproach(a , n, i));
    }

    return dp[index] = ans;
}

ll max_non_adj_sum(vcll a, ll index) {
    ll n = a.size();

    if (n == 1) {
        return a[0];
    }

    if (n == 2) {
        return max(a[0] , a[1]);
    }

    vcll dp(n , 0);
    dp[0] = a[0];
    dp[1] = max(0ll , max(a[0] , a[1]));

    lol(i, 2, n) {
        dp[i] = max(a[i] + dp[i - 2] , dp[i - 1]);
    }

    return dp[n - 1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0);
    // 23-06-2021 20:25:44 IST

    ll n , cost;
    cin >> n;
    vcll a(n);
    for (auto &x : a) cin >> x;

    // lol(i, 0, n) {
    //     cost = max(cost , myApproach(a, n, i));
    // }

    cost = max_non_adj_sum(a, 0);

    cout << cost;
}
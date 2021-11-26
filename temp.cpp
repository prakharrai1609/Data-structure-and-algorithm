/*    Author : Prakhar Rai    */
#include<bits/stdc++.h>
using namespace std;

typedef long long          ll;
typedef long double        ld;

#define FIO         ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define LB(x,num)   lower_bound(x.begin(),x.end(),num) - x.begin()
#define UB(x,num)   upper_bound(x.begin(),x.end(),num) - x.begin()
#define BS(x,num)   binary_search(x.begin(),x.end(),num)
#define ln(s)       ll(s.length())
#define sz(a)       ll(a.size())
#define pb          push_back
#define mp          make_pair
#define fs          first
#define sc          second
#define vci         vector<int>
#define vcll        vector<ll>
#define vcd         vector<long double>
#define line(x)     sort(x.begin(),x.end())
#define all(x)      x.begin(),x.end()
#define endl        "\n"
#define vc          vector
#define loop(i,a,b) for(int i = a; i < b; i++)
#define lol(i,a,b)  for(ll i = a; i < b; i++)
#define lod(i,a,b)  for(ld i = 0; i < b; i++)
#define yes         "YES"
#define no          "NO"

const int mod = 1e9 + 7;
const int N = 2e5 + 5;

template <typename T>
void print(T &&t)  { cout << t << "\n"; }
template <typename T, typename... Args>
void print(T &&t, Args &&... args)
{
    cout << t << " ";
    print(forward<Args>(args)...);
}

template <typename T>
void read(T &&t)  { cin >> t;}
template <typename T, typename... Args>
void read(T &&t, Args &&... args)
{
    cin >> t;
    read(forward<Args>(args)...);
}

#ifndef ONLINE_JUDGE
#define pika(x) cerr << #x <<" "; _print(x); cerr << endl;
#else
#define pika(x)
#endif

void _print(ll t) {cerr << t;}
void _print(int t) {cerr << t;}
void _print(string t) {cerr << t;}
void _print(char t) {cerr << t;}
void _print(ld t) {cerr << t;}
void _print(double t) {cerr << t;}

template <class T, class V> void _print(pair <T, V> p);
template <class T> void _print(vector <T> v);
template <class T> void _print(set <T> v);
template <class T, class V> void _print(map <T, V> v);
template <class T> void _print(multiset <T> v);
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.fs); cerr << ","; _print(p.sc); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i); cerr << " ";} cerr << "]";}

// == == == == == == == == == == == main code == == == == == == == == == == ==







void solve() {

}



int main() {
    FIO;
    int t;
    t = 1;
    // cin >> t;
    for (int i = 1; i <= t; i++) {
        // cout << "Case #" << i << ": ";
        solve();
    }

}

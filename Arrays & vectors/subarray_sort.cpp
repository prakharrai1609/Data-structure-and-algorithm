#include<bits/stdc++.h>
#define ll long long
#define deb cout << "\nDebug\n"
#define vcll vector<ll>
using namespace std;

void init() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
}

/*
	Sort the smallest part of the array such that the entire array becomes sorted
	--> Return the first and last index
*/

void findSubarrayMyapproach(vcll a) {
	ll temp_lb = -1 , ub = -1, lb;
	ll n = a.size();

	for (ll i = 1; i < n; i++) {
		if (a[i - 1] > a[i]) {
			temp_lb = i - 1;
			break;
		}
	}

	if (temp_lb == -1) {
		cout << -1 << ' ' << -1;
		return;
	}

	if (temp_lb == n - 1) {
		cout << 0 << ' ' << n - 1;
		return;
	}

	ll comparator = a[temp_lb];
	cout << comparator << endl;

	for (ll i = temp_lb + 1; i < n; i++) {
		if (a[i] >= comparator) {
			ub = i - 1;
			break;
		}
	}

	if (ub == -1) {
		ub = n - 1;
	}

	for (ll i = ub; i >= 0; i--) {
		if (a[i] > a[temp_lb]) {
			lb = i;
		}
	}

	lb = min (lb , temp_lb);
	cout << lb << ' ' << ub;

}

void findSubarray(vcll a) {

	ll n = a.size();

	ll largest , smallest;
	largest = -1 , smallest = INT_MAX;
	for (ll i = 0; i < n; i++) {

		if (i == 0) {
			if (a[i + 1] < a[i]) {
				largest = smallest = a[i];
			}
			continue;
		}

		if (i == n - 1) {
			if (a[i] < a[i - 1]) {
				smallest = min(smallest , a[i]);
			}
			continue;
		}

		if (a[i] > a[i - 1] and a[i + 1] <= a[i]) {
			largest = max(largest , a[i]);
			smallest = min(smallest , a[i]);
		}

		if (a[i] < a[i - 1] and a[i] < a[i + 1]) {
			largest = max(largest , a[i]);
			smallest = min(smallest , a[i]);
		}
	}

	cout << largest << ' ' << smallest;

}

/*

#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;

bool outOfOrder(vector<int> arr,int i){
	int x = arr[i];
	if(i==0){
		return x > arr[1];
	}
	if(i==arr.size()-1){
		return x < arr[i-1];
	}
	return x > arr[i+1] or x < arr[i-1];

}

pair<int,int> subarraySort(vector<int> arr) {

	int smallest = INT_MAX;
	int largest = INT_MIN;

	for(int i=0;i<arr.size();i++){
		int x = arr[i];

		if(outOfOrder(arr,i)){
			smallest = min(smallest,x);
			largest = max(largest,x);
		}
	}

	//next step find the right index where smallest and largest lie (subarray) for out solution
	if(smallest==INT_MAX){
		return {-1,-1};
	}

	int left = 0;
	while(smallest >= arr[left]){
		left++;
	}
	int right = arr.size() - 1;
	while(largest <= arr[right]){
		right--;
	}

	return {left,right};

}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 8, 6, 7, 9, 10, 11};
    auto p = subarraySort(arr);
    cout<< p.first <<" and "<<p.second <<endl;

    return 0;
}

*/

int main() {
	init();
	ios_base::sync_with_stdio(false); cin.tie(NULL);

	ll n; cin >> n;
	vcll a(n);
	for (ll i = 0; i < n; i++) cin >> a[i];

	// findSubarrayMyapproach(a);
	findSubarray(a);

}
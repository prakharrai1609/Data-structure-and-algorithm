#include<bits/stdc++.h>
#define ll long long
using namespace std;

class node {
public:
	ll data;
	node *left;
	node *right;

	node (ll data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

node * build() {
	ll d; cin >> d;
	if (d == -1) {
		return NULL;
	}

	node * root = new node(d);
	root->left = build();
	root->right = build();

	return root;
}

class HBpair {
public:
	ll height;
	bool balance;
};

HBpair heightBalance(node * root) {
	HBpair p;
	if (root == NULL) {
		p.height = 0;
		p.balance = true;
		return p;
	}

	HBpair left = heightBalance(root->left);
	HBpair right = heightBalance(root->right);

	p.height = max(left.height , right.height) + 1;

	if (abs(left.height - right.height) <= 1 and left.balance and right.balance) {
		p.balance = true;
	} else {
		p.balance = false;
	}

	return p;
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	node * root = build();
	HBpair p = heightBalance(root);
	if (p.balance) {
		cout << "Balanced";
	}	 else {
		cout << "Unbalanced";
	}


}

/*
TEST INPUT : 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
TEST OUTPUT : Unbalanced
*/
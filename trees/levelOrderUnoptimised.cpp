#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*	IN THE WORST CASE THIS TRAVERSAL (this particular code)
 	GIVES ORDER OF O(n^2) COMPLEXITY  */

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

ll height(node * root) {
	if (root == NULL) {
		return 0;
	}

	ll hl = height(root->left);
	ll hr = height(root->right);

	return 1 + max(hl, hr);
}

void kthleveltraversal(node * root, ll k) {
	if (root == NULL)
		return;

	if (k == 1)
		cout << root->data << ' ';

	kthleveltraversal(root->left, k - 1);
	kthleveltraversal(root->right, k - 1);
}

void allLevelTraversal(node * root) {
	ll h = height(root);
	for (ll i = 1; i <= h; i++) {
		kthleveltraversal(root, i);
		cout << endl;
	}
}

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

int main()
{
#ifndef ONLINE_JUDGGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	node * root = build();
	// cout << height(root);
	// kthleveltraversal(root , 3);
	allLevelTraversal(root);
}
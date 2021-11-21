#include<bits/stdc++.h>
#define ll long long
using namespace std;

class node {
public:
	ll data;
	node * left;
	node * right;

	node (ll data) {
		this->data = data;
		left = NULL;
		right = NULL;
	}
};

node * build() {
	ll d; cin >> d;
	if (d == -1)
		return NULL;

	node * root = new node(d);
	root->left = build();
	root->right = build();

	return root;
}

ll sum(node * root) {
	if (root == NULL)
		return 0;

	return root->data + sum(root->left) + sum(root->right);
}

ll nodeCount(node * root) {
	if (root == NULL)
		return 0;

	return 1 + nodeCount(root->left) + nodeCount(root->right);

//	THIS METHOD IS CORRECT TOO -- better understanding--
	// ll s1 , s2;
	// s1 = s2 = 0;

	// s1 = nodeCount(root->left);
	// s2 = nodeCount(root->right);

	// return (1 + s1 + s2);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	node * root = build();
	cout << nodeCount(root) << endl;
	cout << sum(root);
}

/*
TEST INPUT1 : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
TEST INPUT2 : 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
*/
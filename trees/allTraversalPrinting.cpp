#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*  THIS CONTAINS PRE-ORDER , IN-ORDER , POST-ORDER TRAVERSAL  */

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

void printPreorder(node * root) {

	if (root == NULL) {
		return;
	}
	cout << root->data << ' ';
	printPreorder(root->left);
	printPreorder(root->right);
}

void printInorder(node * root) {
	if (root == NULL)
		return;

	printInorder(root->left);
	cout << root->data << ' ';
	printInorder(root->right);
}

void printPostorder(node * root) {
	if (root == NULL)
		return;

	printPostorder(root->left);
	printPostorder(root->right);
	cout << root->data << ' ';
}

int main() {
#ifndef ONLINE_JUDGGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	node * root = build();
	printPreorder(root);
	cout << endl;
	printInorder(root);
	cout << endl;
	printPostorder(root);
	cout << endl;
	// levelOrder(root);
	return 0;
}

/*
TEST INPUT1 : 3 4 -1 6 -1 -1 5 1 -1 -1 -1
TEST INPUT2 : 8 10 1 -1 -1 6 9 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1
*/
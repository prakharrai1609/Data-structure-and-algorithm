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

void levelOrderTraversal(node * root) {
	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node * head = q.front();
		q.pop();

		cout << head->data << ' ';

		if (head->left)
			q.push(head->left);
		if (head->right)
			q.push(head->right);

	}
}

void levelOrderTraversalModified(node * root) {
	queue<node*> q;
	q.push(root);
	q.push(NULL);

	while (!q.empty()) {
		node * head = q.front();

		if (head == NULL) {
			cout << endl;
			q.pop();
			if (!q.empty()) {
				q.push(NULL);
			}
		} else {

			q.pop();
			cout << head->data << ' ';

			if (head->left)
				q.push(head->left);
			if (head->right)
				q.push(head->right);
		}
	}
}

/*
	Todo: level order build
*/

node * Buildlevel_ot() {
	int val;
	cin >> val;

	node * root = new node(val);
	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node * temp = q.front();
		q.pop();

		int l , r;
		cin >> l >> r;

		if (l != -1) {
			node * left = new node(l);
			temp->left = left;
			q.push(left);
		}

		if (r != -1) {
			node * right = new node(r);
			temp->right = right;
			q.push(right);
		}
	}

	return root;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	node * root = build();
	levelOrderTraversalModified(root);

}
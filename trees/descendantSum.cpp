#include<bits/stdc++.h>
#define ll long long
using namespace std;

//	IN THIS QUESTION WE TAKE THE CHILD NODES AND ADD THE VALUE OF CHILD NODES TO PARENT
//  NODES .

class node {
public:
	ll data;
	node * left;
	node * right;

	node (ll d) {
		data = d;
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

ll childSum(node * root) {
	if (root == NULL)
		return 0;
	if (root->left == NULL and root->right == NULL) {
		return root->data;
	}

	ll leftsum = childSum(root->left);
	ll rightsum = childSum(root->right);
	ll temp = root->data;

	root->data = leftsum + rightsum;
	return temp + root->data;
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

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	node * root = build();
	levelOrderTraversalModified(root);
	childSum(root);
	cout << endl;
	levelOrderTraversalModified(root);

}
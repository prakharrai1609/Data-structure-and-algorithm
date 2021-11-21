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

node * build(ll pre[], ll ino[], ll s, ll e) {
	static ll i = 0;

	if (s > e) {
		return NULL;
	}

	node * root = new node(pre[i]);
	ll index = -1;
	for (ll j = s; j <= e; j++) {
		if (ino[j] == pre[i]) {
			index = j;
			break;
		}
	}

	i++;
	root->left = build(pre, ino, s, index - 1);
	root->right = build(pre, ino, index + 1, e);
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


	ll pre[] = {1, 2, 3, 4, 8, 5, 6, 7};
	ll ino[] = {3, 2, 8, 4, 1, 6, 7, 5};
	ll n = 8;
	node * root = build(pre, ino, 0, n - 1);
	levelOrderTraversalModified(root);

}
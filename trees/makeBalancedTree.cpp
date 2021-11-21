#include<bits/stdc++.h>
#define ll long long
using namespace std;

/*	BUILDING A TREE FROM AN ARRAY  */
// MAKE THE MIDDLE ELEMENT AS ROOT AND REST AS CHILD AND REEAT RECURIVELY

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

node * build(ll a[], ll s, ll e) {
	if (s > e)
		return NULL;

	ll mid = (s + e) / 2;
	node * root = new node(a[mid]);

	root->left = build(a, s, mid - 1);
	root->right = build(a, mid + 1, e);

	return root;
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
			cout << head->data << ',';

			if (head->left)
				q.push(head->left);
			if (head->right)
				q.push(head->right);
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	ll a[] = {1, 2, 3, 4, 5, 6, 7};
	ll n = 7;
	node * root = build(a, 0, n - 1);
	levelOrderTraversalModified(root);

}
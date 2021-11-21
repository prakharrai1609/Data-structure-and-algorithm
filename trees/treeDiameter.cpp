#include<bits/stdc++.h>
#define ll long long
using namespace std;

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

/*	THIS METHOD WORKS IN O(n^2)  */

ll height(node * root) {

	if (root == NULL)
		return 0;
	return max(1 + height(root->left) , 1 + height(root->right));
}

ll diameter(node * root) {

	if (root == NULL)
		return 0;

	ll s1 = height(root->left);
	ll s2 = height(root->right);

	ll op1 =  s1 + s2;
	ll op2 = diameter(root->left);
	ll op3 = diameter(root->right);

	return max(op1 , max(op2 , op3));
}

/*	BOTTOM UP APPROACH USING POST ORDER TRAVERSAL -- WORKS IN O(n)	*/

class Pair {
public:
	ll height;
	ll diameter;
};

Pair fastDiameter(node * root) {
	Pair p;
	if (root == NULL) {
		p.height = p.diameter = 0;
		return p;
	}

	Pair left = fastDiameter(root->left);
	Pair right = fastDiameter(root->right);

	p.height = 1 + max(left.height , right.height);
	p.diameter = max(left.height + right.height , max(left.diameter , right.diameter));
	return p;

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	node * root = build();
	Pair p = fastDiameter(root);
	cout << p.height << ' ' << p.diameter;
}
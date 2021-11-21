#include<bits/stdc++.h>
using namespace std;

#define FIO  	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define ll   	long long
#define vcll 	vector<ll>
#define newl 	'\n'

class node {
public:
	node * left;
	node * right;
	int data;
	node(int data) {
		this->data = data;
		left = right = nullptr;
	}
};

node * build() {
	int d;
	cin >> d;
	if (d == -1)
		return nullptr;

	node * root = new node(d);
	root->left = build();
	root->right = build();

	return root;
}

void level_ot(node * root) {
	queue<node*> q;
	q.push(root);
	q.push(nullptr);

	while (!q.empty()) {
		node * temp = q.front();

		if (temp == nullptr) {
			cout << newl;
			q.pop();
			if (!q.empty())
				q.push(nullptr);
		} else {

			cout << temp->data << ' ';
			q.pop();

			if (temp->left)
				q.push(temp->left);

			if (temp->right)
				q.push(temp->right);
		}
	}
}

int height(node * root) {
	if (!root)
		return 0;
	return 1 + max(height(root->left) , height(root->right));
}

pair<int, bool> isHeightBalanced(node * root) {

	pair<int, bool> p;

	if (!root) {
		p.first = 0;
		p.second = true;
		return p;
	}

	pair<int, bool> Left, Right;
	Left = isHeightBalanced(root->left);
	Right = isHeightBalanced(root->right);

	int height = 1 + (Left.first , Right.first);

	if (abs(Left.first - Right.first) <= 1 and Left.second and Right.second) {
		return {height , true};
	}

	return {height, false};
}

void levelot(node * root) {
	queue<node*> q;
	q.push(root);

	while (!q.empty()) {
		node * temp = q.front();
		q.pop();
		cout << temp->height << ' ';

		if (temp->left)
			q.push(temp->left);

		if (temp->right)
			q.push(temp->right);
	}
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	node * root = build();
	level_ot(root);
	if (isHeightBalanced(root).second)
		cout << "Height balanced";
	else
		cout << "Not height balanced";
}
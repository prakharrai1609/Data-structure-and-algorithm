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

// ==================== BOILERPLATE FOR TREES =======================

void printK(node * root, int k) {
	int level = 1;
	queue<node*> q;
	q.push(root);
	q.push(nullptr);

	vector<int> ans;

	while (!q.empty()) {
		node * temp = q.front();
		q.pop();

		if (temp == nullptr) {
			level++;
			if (!q.empty())
				q.push(nullptr);
		} else {
			if (level == k)
				ans.push_back(temp->data);

			if (temp->left)
				q.push(temp->left);
			if (temp->right)
				q.push(temp->right);
		}
	}

	for (int x : ans)
		cout << x << ' ';

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif

	node * root = build();
	printK(root , 4);

}

// 1 2 4 -1 -1 5 7 -1 -1 -1 3 6 -1 -1 -1
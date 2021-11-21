// node class
class node {
public:
	int value;
	node * left;
	node * right;

	node(int v) {
		value = v;
		left = nullptr;
		right = nullptr;
	}
};


// build a tree in level order fashion
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

#include<bits/stdc++.h>
using namespace std;


// =====================================================
// recursive segment tree
// =====================================================

struct segmenttree {
	int n;
	vector<int> st;

	segmenttree(int n) {
		this->n = n;
		st.resize(4 * n, 0);
	}

	// helper functions
	void build(int start, int end, int node, vector<int> v) {
		if (start == end) {
			st[node] = v[start];
			return;
		}

		int mid = (start + end) / 2;
		build(start, mid, 2 * node + 1, v);
		build(mid + 1, end, 2 * node + 2, v);

		st[node] = st[2 * node + 1] + st[2 * node + 2];
	}

	int query(int l, int r, int start, int end, int node) {
		// no overlap
		if (start > r or end < l) {
			return 0;
		}

		// complete overlap
		if (start >= l and end <= r) {
			return st[node];
		}

		// partial overlap
		int mid = (start + end) / 2;
		int q1 = query(l, r, start, mid, 2 * node + 1);
		int q2 = query(l, r, mid + 1, end, 2 * node + 2);

		return (q1 + q2);
	}

	void update(int start, int end, int index, int value, int node) {
		if (start == end) {
			st[node] = value;
			return;
		}

		int mid = (start + end) / 2;
		if (index <= mid) {
			update(start, mid, index, value, 2 * node + 1);
		} else {
			update(mid + 1, end, index, value, 2 * node + 2);
		}
		st[node] = st[2 * node + 1] + st[2 * node + 2];
	}

	// called functions
	void build(vector<int> v) {
		build(0, n - 1, 0, v);
	}

	int query(int l, int r) {
		return query(l, r, 0, n - 1, 0);
	}

	void update(int x, int y) {
		update(0, n - 1, x, y, 0);
	}
};

// =====================================================
// iterative segment tree
// =====================================================

const int N = 1e6;  // limit for array size
int n;  // array size
int t[2 * N];

void build() {  // build the tree
	for (int i = n - 1; i > 0; --i) t[i] = t[i << 1] + t[i << 1 | 1];
}

void modify(int p, int value) {  // set value at position p
	for (t[p += n] = value; p > 1; p >>= 1) t[p >> 1] = t[p] + t[p ^ 1];
}

int query(int l, int r) {  // sum on interval [l, r)
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l & 1) res += t[l++];
		if (r & 1) res += t[--r];
	}
	return res;
}


int main() {
	vector<int> a{1, 2, 3, 4, 5, 6, 7, 8};
	segmenttree tree(a.size());
	tree.build(a);
	cout << tree.query(0 , 7) << endl;
	// cout << tree.query(1 , 2) << endl;
	// cout << tree.query(6 , 6) << endl;
	// cout << tree.query(2 , 5) << endl;
	tree.update(0, 11);
	cout << tree.query(0 , 7) << endl;
}
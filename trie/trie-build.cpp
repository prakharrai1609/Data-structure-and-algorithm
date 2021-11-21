#include<bits/stdc++.h>
using namespace std;

#define FIO  	ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll   	long long
#define endl 	'\n'
#define _(x) 	cerr << #x << ' ' << x << endl;

inline void init() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
#endif
	FIO;
}

class node {
public:
	char c;
	map<char, node *> m;
	bool isterminal;

	node (char c) {
		this->c = c;
		isterminal = false;
	}
};

class trie {
public:
	node * root;

	trie() {
		root = new node('\0');
	}

	// insert in the trie
	void insert(string word) {
		node * temp = root;
		for (char c : word) {
			if (temp->m.count(c) == 0) {
				temp->m[c] = new node(c);
			}
			temp = temp->m[c];
		}
		temp->isterminal = true;
	}

	// search in a trie
	bool search(string word) {
		node * temp = root;
		for (char c : word) {
			if (temp->m[c]) {
				temp = temp->m[c];
			} else {
				return false;
			}
		}

		return temp->isterminal;
	}

};


int main() {
	init();
	trie t;
	int n;
	cin >> n;
	while (n--) {
		string s;
		cin >> s;
		t.insert(s);
	}

	if (t.search("news"))
		cout << "present";
	else
		cout << "not found";
}

/*
sample input:

8
ababa
ba
ababa
bb
aaa
aaaa
aababa
ababa

*/
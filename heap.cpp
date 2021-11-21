#include<bits/stdc++.h>
using namespace std;

#define FIO      ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int       long long
#define endl     '\n'
#define _(x)     cerr << #x << ' ' << x << endl;

class Heap {
    vector<int> v;
    bool minHeap;

    bool compare(int a, int b)
    {
        if (minHeap)
            return a < b;
        else
            return a > b;
    }

public:
    Heap(int default_size = 10, bool type = true)
    {
        v.reserve(default_size);
        v.push_back(-1);
        minHeap = type;
    }

    void push(int data)
    {
        v.push_back(data);
        int index = v.size() - 1;
        int parent = index / 2;

        while (index > 1 and compare(v[index] , v[parent])) {
            swap(v[index], v[parent]);
            index = parent;
            parent = parent / 2;
        }
    }

    int top()
    {
        return v[1];
    }

    void pop()
    {
        int idx = v.size() - 1;
        swap(v[1], v[idx]);
        v.pop_back();

        heapify(1);
    }

    void heapify(int i)
    {
        int left = 2 * i;
        int right = left + 1;

        int min_index = i;
        int last = v.size() - 1;

        if (left <= last and compare(v[left], v[i]))
            min_index = left;

        if (right <= last and compare(v[right], v[min_index]))
            min_index = right;

        if (min_index != i) {
            swap(v[min_index], v[i]);
            heapify(min_index);
        }
    }
};

int32_t main() {
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
#endif
    FIO;

    Heap h(10);
    h.push(5);
    h.push(4);
    h.push(3);
    h.push(2);
    h.push(1);

    for (int i = 0; i < 5; i++) {
        cout << h.top() << ' ';
        h.pop();
    }
}
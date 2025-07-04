#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007LL
// Segment Tree for sum queries and point updates with modulo
struct SegmentTree {
    int n;
    vector<long long> tree;

    // Initialize with input array a
    SegmentTree(const vector<int>& a) {
        n = a.size();
        tree.resize(4 * n);
        build(a, 1, 0, n - 1);
    }

    // Build the tree: node covers range [l..r]
    void build(const vector<int>& a, int node, int l, int r) {
        if (l == r) {
            tree[node] = a[l] % MOD;
        } else {
            int mid = (l + r) / 2;
            build(a, 2 * node, l, mid);
            build(a, 2 * node + 1, mid + 1, r);
            tree[node] = (tree[2 * node] + tree[2 * node + 1]) % MOD;
        }
    }

    // Point update: set a[idx] = val
    void update(int idx, int val) {
        update(1, 0, n - 1, idx, val);
    }
    void update(int node, int l, int r, int idx, int val) {
        if (l == r) {
            tree[node] = val % MOD;
        } else {
            int mid = (l + r) / 2;
            if (idx <= mid)
                update(2 * node, l, mid, idx, val);
            else
                update(2 * node + 1, mid + 1, r, idx, val);
            tree[node] = (tree[2 * node] + tree[2 * node + 1]) % MOD;
        }
    }

    // Range sum query over [ql..qr]
    long long query(int ql, int qr) {
        return query(1, 0, n - 1, ql, qr);
    }
    long long query(int node, int l, int r, int ql, int qr) {
        if (qr < l || r < ql) {
            // no overlap
            return 0;
        }
        if (ql <= l && r <= qr) {
            // total overlap
            return tree[node];
        }
        // partial overlap
        int mid = (l + r) / 2;
        long long leftSum = query(2 * node, l, mid, ql, qr);
        long long rightSum = query(2 * node + 1, mid + 1, r, ql, qr);
        return (leftSum + rightSum) % MOD;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> x(n);
    set<int> S;
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        S.insert(x[i]);
    }
    vector<int> vals;
    for (auto s : S) vals.push_back(s);
    vector<int> dp(S.size(), 0);
    SegmentTree ST(dp);
    for (int i = 0; i < n; i++) {
        int pos = lower_bound(vals.begin(), vals.end(), x[i]) - vals.begin();
        long long sum = ST.query(0, pos);
        ST.update(pos, (sum + 1) % MOD);
    }
    cout << ST.query(0, n - 1) % MOD;
    return 0;
}
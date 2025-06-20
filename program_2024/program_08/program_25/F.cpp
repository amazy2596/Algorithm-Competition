#include <bits/stdc++.h>
#define int long long
using namespace std;

class SegmentTree
{

private:
    vector<int> tree;
    vector<int> data;
    int n;

    void build(int node, int start, int end)
    {
        if (start == end)
            tree[node] = data[start];
        else 
        {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid);
            build(2 * node + 2, mid + 1, end);

            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void update(int node, int start, int end, int idx, int value)
    {
        if (start == end)
        {
            data[idx] = value;
            tree[node] = value;
        }
        else 
        {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node + 1, start, mid, idx, value);
            else 
                update(2 * node + 2, mid + 1, end, idx, value);

            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int start, int end, int l, int r)
    {
        if (r < start || l > end)
            return INT_MAX;
        else if (l <= start && end <= r)
            return tree[node];
        int mid = (start + end) / 2;
        int left_min = query(2 * node + 1, start, mid, l, r);
        int right_min = query(2 * node + 2, mid + 1, end, l, r);
        return min(left_min, right_min);
    }

public:
    SegmentTree(const vector<int>& input_data)
    {
        data = input_data;
        n = data.size();
        tree.resize(4 * n, 0);
        build(0, 0, n - 1);
    }

    void update(int idx, int value)
    {
        update(0, 0, n - 1, idx, value);
    }

    int query(int l, int r)
    {
        return query(0, 0, n - 1, l, r);
    }

    int getMin()
    {
        return tree[0];
    }

};

class GlobalSegmentTree {
private:
    vector<int> tree;
    int n;

    void build(int node, int start, int end, const vector<int>& min_vals) {
        if (start == end) {
            tree[node] = min_vals[start];
        } else {
            int mid = (start + end) / 2;
            build(2 * node + 1, start, mid, min_vals);
            build(2 * node + 2, mid + 1, end, min_vals);
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    void update(int node, int start, int end, int idx, int value) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid) {
                update(2 * node + 1, start, mid, idx, value);
            } else {
                update(2 * node + 2, mid + 1, end, idx, value);
            }
            tree[node] = min(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }

    int query(int node, int start, int end, int l, int r) {
        if (r < start || l > end) {
            return LLONG_MAX;
        }
        if (l <= start && end <= r) {
            return tree[node];
        }
        int mid = (start + end) / 2;
        int left_min = query(2 * node + 1, start, mid, l, r);
        int right_min = query(2 * node + 2, mid + 1, end, l, r);
        return min(left_min, right_min);
    }

public:
    GlobalSegmentTree(const vector<int>& min_vals) {
        n = min_vals.size();
        tree.resize(4 * n, LLONG_MAX);
        build(0, 0, n - 1, min_vals);
    }

    void update(int idx, int value) {
        update(0, 0, n - 1, idx, value);
    }

    int query(int l, int r) {
        return query(0, 0, n - 1, l, r);
    }
};

void solve()
{
    int n;
    cin >> n;
    vector<SegmentTree> trees;
    vector<int> mn(n);

    for (int i = 0; i < n; i++)
    {
        int m;
        cin >> m;
        vector<int> a(m);
        for (int j = 0; j < m; j++)
            cin >> a[j];
        trees.emplace_back(a);
        mn[i] = trees.back().getMin();
    }

    GlobalSegmentTree global_tree(mn);

    int q;
    cin >> q;
    while (q--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int i, j, x;
            cin >> i >> j >> x;
            i--, j--;
            trees[i].update(j, x);
            global_tree.update(i, trees[i].getMin());
        }
        else 
        {
            int i;
            cin >> i;
            i--;
            cout << global_tree.query(0, i) << "\n";
        }
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
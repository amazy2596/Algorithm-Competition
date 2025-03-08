#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

struct Node
{
    int l, r;
    int prefix, suffix, best;
    int first, last;

    Node() : l(0), r(0), prefix(0), suffix(0), best(0), first(0), last(0) {}
};

vector<int> d;
vector<Node> tree;
const int mod = 1e9 + 7;

Node merge(const Node left, const Node right)
{
    Node res;
    res.l = left.l;
    res.r = right.r;
    res.first = left.first;
    res.last = right.last;

    res.prefix = left.prefix;
    if (left.prefix == left.r - left.l + 1 && left.last * right.first == -1)
        res.prefix = left.prefix + right.prefix;
    
    res.suffix = right.suffix;
    if (right.suffix == right.r - right.l + 1 && left.last * right.first == -1)
        res.suffix = left.suffix + right.suffix;

    int cross = 0;
    if (left.last * right.first == -1)
        cross = left.suffix + right.prefix;
    
    res.best = max({res.prefix, res.suffix, cross});

    return res;
}

void build(int node, int start, int end)
{
    if (start == end)
    {
        tree[node].l = start;
        tree[node].r = end;
        tree[node].first = tree[node].last = d[start];
        tree[node].prefix = tree[node].suffix = tree[node].best = (d[start] == 0 ? 0 : 1);
    }
    else 
    {
        int mid = (start + end) / 2;
        build(node * 2, start, mid);
        build(node * 2 + 1, mid + 1, end);

        tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
    }
}

Node query(int node, int l, int r)
{
    if (tree[node].l >= l && tree[node].r <= r)
        return tree[node];

    int mid = (tree[node].l + tree[node].r) / 2;
    if (r <= mid)
        return query(node * 2, l, r);
    else if (l > mid)
        return query(node * 2 + 1, l, r);
    else 
    {
        Node left = query(node * 2, l, r);
        Node right = query(node * 2 + 1, l, r);

        return merge(left, right);
    }
}

void solve()
{
    int n, q;
    cin >> n >> q;
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    d.resize(n + 1);
    for (int i = 1; i <= n - 1; i++)
        d[i] = (h[i + 1] - h[i] > 0 ? 1 : (h[i + 1] - h[i] < 0 ? -1 : 0));

    if(n == 1) {
        int ans = 0;
        for (int i = 1; i <= q; i++) {
            int l, r;
            cin >> l >> r;
            ans = (ans + i) % mod;
        }
        cout << ans % mod << "\n";
        return;
    }
    
    tree.resize(4 * n + 5);
    build(1, 1, n - 1);

    int ans = 0;
    for (int i = 1; i <= q; i++)
    {
        int l, r;
        cin >> l >> r;
        if (l == r)
            ans = (ans + i) % mod;
        else 
        {
            Node res = query(1, l, r - 1);
            ans = (ans + ((res.best + 1) * i) % mod) % mod;
        }
    }

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
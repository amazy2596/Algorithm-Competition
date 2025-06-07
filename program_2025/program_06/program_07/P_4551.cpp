#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

struct Trie 
{
    struct Node
    {
        vector<int> nex;
        int cnt = 0, end = 0;

        Node(int m) : nex(m) {}
    };

    int m, mx = 31;
    vector<Node> tree;
    Trie(int _m) : m(_m), tree(1, Node(_m)) {}

    int newNode()
    {
        tree.emplace_back(Node(m));
        return tree.size() - 1;
    }
    
    void insert(string s) 
    {
        int p = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            int c = s[i] - 'a';
            if (!tree[p].nex[c])
                tree[p].nex[c] = newNode();
            
            p = tree[p].nex[c];
            tree[p].cnt++;
        }

        tree[p].end++;
    }

    void insert(int x, int t = 1)
    {
        int p = 0;
        for (int k = mx; k >= 0; k--)
        {
            int bit = (x >> k) & 1;
            if (!tree[p].nex[bit])
                tree[p].nex[bit] = newNode();
            
            p = tree[p].nex[bit];
            tree[p].cnt++;
        }

        tree[p].end++;
    }

    int find(string s) 
    {
        int p = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            int c = s[i] - 'a';
            if (!tree[p].nex[c])
                return 0;

            p = tree[p].nex[c];
        }

        return tree[p].end;
    }

    int query(int x)
    {
        int p = 0, res = 0;
        for (int k = mx; k >= 0; k--)
        {
            int bit = (x >> k) & 1;
            if (tree[p].nex[bit ^ 1])
            {
                res |= (1ll << k);
                p = tree[p].nex[bit ^ 1];
            }
            else 
                p = tree[p].nex[bit];
        }

        return res;
    }
};

void solve()
{
    int n;
    cin >> n;
    vector adj(n + 1, vector<int>());
    map<pair<int, int>, int> mp;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        mp[{u, v}] = w;
        mp[{v, u}] = w;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> val(n + 1);
    auto dfs = [&](auto dfs, int u, int p) -> void
    {
        val[u] = val[p] ^ mp[{u, p}];
        for (auto v : adj[u])
        {
            if (v == p)
                continue;
            
            dfs(dfs, v, u);
        }
    };

    dfs(dfs, 1, 0);

    Trie t(2);
    for (int i = 1; i <= n; i++)
        t.insert(val[i], 1);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, t.query(val[i]));

    cout << ans << "\n";
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
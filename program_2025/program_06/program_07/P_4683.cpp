#include <bits/stdc++.h>
#define uint uint64_t
// #define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r){ return uniform_int_distribution<uint>(l, r)(rng); };

template<size_t M>
struct Trie 
{
    struct Node
    {
        array<int, M> nex;
        int cnt = 0, end = 0, depth = 0;

        Node() { nex.fill(0); }
    };

    int mx = 31;
    vector<Node> tree;
    Trie(int n = 0)
    {
        tree.reserve(n);
        tree.emplace_back();
    } 

    int newNode()
    {
        tree.emplace_back(Node());
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
            tree[p].depth = i + 1;
            tree[p].cnt++;
        }

        tree[p].end++;
    }

    void insert(int x)
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
    Trie<26> t;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        t.insert(s);
    }

    auto dfs = [&](auto dfs, int u) -> int
    {
        int mx = 0;
        for (int c = 0; c < 26; c++)
        {
            if (t.tree[u].nex[c] != 0)
                mx = max(mx, dfs(dfs, t.tree[u].nex[c]));
        }

        t.tree[u].depth = max(t.tree[u].depth, mx);

        return t.tree[u].depth;
    };

    dfs(dfs, 0);

    vector<char> ans;
    
    auto dfs1 = [&](auto dfs1, int u) -> void
    {
        vector<pair<int, int>> order;    
        for (int c = 0; c < 26; c++)
        {
            if (t.tree[u].nex[c])
            {
                int p = t.tree[u].nex[c];
                order.emplace_back(t.tree[p].depth, c);
            }
        }

        sort(order.begin(), order.end());

        for (auto [_, c] : order)
        {
            int p = t.tree[u].nex[c];
            ans.push_back(c + 'a');
            if (t.tree[p].end != 0)
                ans.push_back('P');
            dfs1(dfs1, p);
            ans.push_back('-');
        }
    };

    dfs1(dfs1, 0);

    while (ans.back() == '-')
        ans.pop_back();

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++)
        cout << ans[i] << "\n";
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    // init();
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
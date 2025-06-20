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

    bool find(string s, vector<vector<int>> &adj, vector<int> &d)
    {
        int p = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            int c = s[i] - 'a';

            for (int k = 0; k < 26; k++)
            {
                if (k == c)
                    continue;
                if (tree[p].nex[k])
                    adj[c].push_back(k), d[k]++;
            }

            if (tree[p].end != 0)
                return false;

            p = tree[p].nex[c];
        }

        return true;
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

    Trie t(26);
    vector<string> s(n);
    for (int i = 0; i < n; i++)
    {
        cin >> s[i];
        t.insert(s[i]);
    }

    vector<string> ans;
    vector<vector<int>> adj(26, vector<int>());
    vector<int> d(26);
    for (int i = 0; i < n; i++)
    {
        adj.assign(26, vector<int>());
        d.assign(26, 0);

        bool ok = t.find(s[i], adj, d);

        if (!ok)
            continue;

        queue<int> q;
        for (int u = 0; u < 26; u++)
        {
            if (d[u] == 0)
                q.push(u);
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int v : adj[u])
            {
                d[v]--;
                if (d[v] == 0)
                    q.push(v);
            }
        }

        for (int u = 0; u < 26; u++)
        {
            if (d[u] != 0)
            {
                ok = 0;
                break;
            }
        }

        if (ok) ans.emplace_back(s[i]);
    }

    cout << ans.size() << "\n";
    for (auto str : ans)
        cout << str << "\n";
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
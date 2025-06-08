#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct AhoCorasick 
{
    struct Node
    {
        array<int, 26> nex;
        vector<int> out;
        int cnt = 0, end = 0, fail = 0, link = 0;

        Node() { nex.fill(0); }
    };

    vector<Node> tree;
    AhoCorasick(int n = 0)
    {
        tree.reserve(n);
        tree.emplace_back();
    } 

    int newNode()
    {
        tree.emplace_back(Node());
        return tree.size() - 1;
    }
    
    void insert(string s, int id) 
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
        tree[p].out.push_back(id);
    }

    void build()
    {
        queue<int> q;
        for (int c = 0; c < 26; c++)
        {
            int v = tree[0].nex[c];
            if (v)
            {
                tree[v].fail = 0;
                q.push(v);
            }
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int c = 0; c < 26; c++)
            {
                int v = tree[u].nex[c];
                if (v)
                {
                    tree[v].fail = tree[tree[u].fail].nex[c];
                    int to = tree[v].fail;
                    if (tree[to].end > 0)
                        tree[v].link = to;
                    else 
                        tree[v].link = tree[to].link;
                    q.push(v);
                }
                else 
                    tree[u].nex[c] = tree[tree[u].fail].nex[c];
            }
        }
    }

    void query(string &s, vector<int> &cnt)
    {
        int node = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int c = s[i] - 'a';
            node = tree[node].nex[c];

            for (int t = node; t; t = tree[t].link)
                for (auto id : tree[t].out)
                    cnt[id]++;
        }
    }
};

void solve()
{
    while (true)
    {
        int n;
        cin >> n;

        if (n == 0)
            return;

        AhoCorasick ac;
        vector<string> s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            ac.insert(s[i], i);
        }

        ac.build();

        string t;
        cin >> t;
        vector<int> cnt(n);
        ac.query(t, cnt);

        int mx = *max_element(cnt.begin(), cnt.end());
        cout << mx << "\n";
        for (int i = 0; i < n; i++)
        {
            if (cnt[i] == mx)
            {
                cout << s[i] << "\n";
            }
        }
    }
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
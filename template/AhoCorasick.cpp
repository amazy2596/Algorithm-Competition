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
        int cnt = 0;
        int end = 0;
        int fail = 0;
        int link = 0;
        int occ = 0;

        Node() { nex.fill(0); }
    };

    vector<Node> tree;
    vector<int> endpos;
    vector<int> bfs;
    AhoCorasick(int n)
    {
        tree.emplace_back();
        endpos.resize(n);
    } 

    int newNode()
    {
        tree.emplace_back(Node());
        return tree.size() - 1;
    }
    
    void insert(string &s, int id = 0) 
    {
        int u = 0;
        for (int i = 0; i < s.length(); i++) 
        {
            int c = s[i] - 'a';
            if (!tree[u].nex[c])
                tree[u].nex[c] = newNode();

            u = tree[u].nex[c];
            tree[u].cnt++;
        }

        tree[u].end++;
        endpos[id] = u;
    }

    void build()
    {
        queue<int> q;
        for (int c = 0; c < 26; c++)
        {
            if (tree[0].nex[c])
            {
                tree[tree[0].nex[c]].fail = 0;
                q.push(tree[0].nex[c]);
            }
        }

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            bfs.push_back(u);
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

    void query(string &s)
    {
        int node = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int c = s[i] - 'a';
            node = tree[node].nex[c];
            tree[node].occ++;
        }

        for (int i = bfs.size() - 1; i >= 0; i--)
        {
            int u = bfs[i];
            tree[tree[u].fail].occ += tree[u].occ;
        }
    }

    void reset()
    {
        for (auto u : bfs)
            tree[u].occ = 0;
        tree[0].occ = 0;
    }
};

void solve()
{
    
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
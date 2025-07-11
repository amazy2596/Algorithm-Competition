#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct Trie 
{
    struct Node
    {
        array<int, 2> nex;
        int cnt = 0, end = 0;

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
    
}

signed main()
{
    // ios::sync_with_stdio(false);
    // cout.tie(nullptr);
    // cin.tie(nullptr);
    int T = 1;
    // cin >> T;
    while (T--)
        solve();
    return 0;
}
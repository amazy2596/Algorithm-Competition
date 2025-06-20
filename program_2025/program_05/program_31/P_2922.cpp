#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

int dx8[8] = {1, 1, 0, -1, -1, -1,  0, 1};
int dy8[8] = {0, 1, 1,  1,  0, -1, -1, -1};
int dx4[4] = {1, 0, -1,  0};
int dy4[4] = {0, 1,  0, -1};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](int l, int r){ return uniform_int_distribution<int>(l, r)(rng); };

struct Node
{
    array<int, 2> next;
    int pass, end;

    Node() : next{0, 0}, pass(0), end(0) {}
};

vector<Node> trie(1);

void insert(string &s)
{
    int p = 0;
    for (auto ch : s)
    {
        int x = ch - '0';
        if (trie[p].next[x] == 0)
        {
            trie[p].next[x] = trie.size();
            trie.emplace_back();
        }
        p = trie[p].next[x];
        trie[p].pass++;
    }
    trie[p].end++;
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<string> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        int len;
        cin >> len;
        for (int j = 0; j < len; j++)
        {
            char ch;
            cin >> ch;
            a[i] += ch;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int len;
        cin >> len;
        for (int j = 0; j < len; j++)
        {
            char ch;
            cin >> ch;
            b[i] += ch;
        }
    }

    vector<int> ans(m);

    auto find = [&](string &s)
    {
        int p = 0;
        int res = 0;
        for (auto ch : s)
        {
            int x = ch - '0';
            if (trie[p].next[x] == 0)
            {
                res += trie[p].pass - trie[p].end;
                return res;
            }
            p = trie[p].next[x];
            res += trie[p].end;
        }

        res += trie[p].pass - trie[p].end;
        return res;
    };

    for (int i = 0; i < n; i++)
        insert(a[i]);
    for (int i = 0; i < m; i++)
        ans[i] += find(b[i]);

    for (int i = 0; i < m; i++)
        cout << ans[i] << "\n";
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
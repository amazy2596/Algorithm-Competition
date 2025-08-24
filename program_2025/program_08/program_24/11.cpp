#include<bits/stdc++.h> 
using namespace std;
using i64 = long long;
const i64 mod = 998244353;

struct Trie
{
    struct Node
    {
        array<int, 26> nex;
        int cnt = 0, end = 0;

        Node() { nex.fill(0); }
    };

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

    void insert(string &s)
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

    i64 query(string &s)
    {
        i64 res = 0;
        int p = 0;
        for (int i = 0; i < s.length(); i++)
        {
            int c = s[i] - 'a';
            if (!tree[p].nex[c])
                return res;

            p = tree[p].nex[c];
            res = (res + tree[p].cnt * 2) % mod;
        }

        return res;
    }
};

void solve()
{
    int n;
    cin >> n;
    i64 ans = 0;
    Trie trie(1e6 + 5);
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        ans = (ans + trie.query(s)) % mod;
        ans = (ans + s.length()) % mod;
        trie.insert(s);
    }

    cout << ans % mod << "\n";
}

int main( )
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
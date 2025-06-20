#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

vector<pair<int, int>> dir8 = {{1, 0}, {1, 1}, {0, 1}, {-1, 1},{-1, 0}, {-1, -1}, {0, -1}, {1, -1}};
vector<pair<int, int>> dir4 = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

struct PAM
{
    struct node
    {
        array<int, 26> nex;
        int fail = 0;
        int len = 0;
        int end = 0;
        int num = 0;
    };

    vector<node> tree;
    string s; // 下标应从1开始
    int last;

    PAM()
    {
        tree.emplace_back();
        tree.emplace_back();
        tree[0].len = 0;
        tree[1].len = -1;

        tree[0].fail = 1;
        tree[1].fail = 1;

        s = " ";
        last = 0;
    }

    int newNode()
    {
        tree.emplace_back();
        return tree.size() - 1;
    }

    int getFail(int u, int i)
    {   
        while (s[i - tree[u].len - 1] != s[i])
            u = tree[u].fail;
        return u;
    }

    void insert(char ch, int i)
    {
        s += ch;
        int c = ch - 'a';
        int u = getFail(last, i);

        if (!tree[u].nex[c])
        {
            int v = newNode();

            tree[v].len = tree[u].len + 2;
            tree[v].fail = tree[getFail(tree[u].fail, i)].nex[c];
            tree[v].num = tree[tree[v].fail].num + 1;

            tree[u].nex[c] = v;
        }

        last = tree[u].nex[c];
        tree[last].end++;
    }

    void count()
    {
        for (int u = tree.size() - 1; u >= 2; u--)
            tree[tree[u].fail].end += tree[u].end;
    }
};

void solve()
{
    string s;
    cin >> s;
    s = " " + s;
    PAM pam;
    
    for (int i = 1; i < s.length(); i++)
        pam.insert(s[i], i);

    pam.count();

    int ans = 0;
    for (int u = 2; u < pam.tree.size(); u++)
        ans = max(ans, pam.tree[u].len * pam.tree[u].end);

    cout << ans << "\n";
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
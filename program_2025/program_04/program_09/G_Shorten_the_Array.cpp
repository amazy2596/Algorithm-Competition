#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int N = 2e5 * 31;
int trie[N][2], cnt[N], tot = 0;

int newNode()
{
    int x = ++tot;
    trie[x][0] = trie[x][1] = 0;
    cnt[x] = 0;
    return x;
}

void init()
{
    tot = 0;
    newNode();
}

void insert(int x, int t)
{
    int o = 1;
    for (int i = 29; i >= 0; i--)
    {
        int &p = trie[o][x >> i & 1];
        if (!p)
            p = newNode();

        o = p;
        cnt[o] += t;
    }
}

int query(int x)
{
    int o = 1;
    int res = 0;
    for (int i = 29; i >= 0; i--)
    {
        int d = x >> i & 1;
        if (cnt[trie[o][d ^ 1]])
        {
            d ^= 1;
            res |= 1ll << i;
        }
        o = trie[o][d];
    }

    return res;
}

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    init();

    int ans = n + 1;
    for (int i = 0, j = 0; i < n; i++)
    {
        insert(a[i], 1);
        while (j <= i && query(a[i]) >= k)
        {
            ans = min(ans, i - j + 1);
            insert(a[j], -1);
            j++;
        }
    }

    if (ans > n)
    {
        cout << "-1\n";
        return;
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
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;
const int INF = INT32_MAX;

const int mod = 1e9 + 7;

void solve()
{
    int n, q;
    cin >> n >> q;

    vector<int> ans(q + 1, 0);
    vector<int> h(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> h[i];

    vector<pair<int, int>> que(q + 1, {0, 0});
    for (int i = 1; i <= q; i++)
        cin >> que[i].first >> que[i].second;

    vector<int> log_table(n + 1);
    log_table[1] = 0;
    for (int i = 2; i <= n; i++)
        log_table[i] = log_table[i / 2] + 1;
    int mx_log = log_table[n] + 1;

    vector mx(n + 1, vector<int>(mx_log, -INF));
    vector mn(n + 1, vector<int>(mx_log, INF));
    auto initST = [&]()
    {
        for (int i = 1; i <= n; i++)
        {
            mx[i][0] = (i % 2 == 0 ? h[i] : -INF);
            mn[i][0] = (i % 2 == 1 ? h[i] : INF);
        }

        for (int j = 1; j < mx_log; j++)        
        {
            for (int i = 1; i + (1ll << j) - 1 <= n; i++)
            {
                mx[i][j] = max(mx[i][j - 1], mx[i + (1ll << (j - 1))][j - 1]);
                mn[i][j] = min(mn[i][j - 1], mn[i + (1ll << (j - 1))][j - 1]);
            }
        }
    };

    auto query = [&](int l, int r)
    {
        int j = log_table[r - l + 1];
        int u = min(mn[l][j], mn[r - (1ll << j) + 1][j]);
        int v = max(mx[l][j], mx[r - (1ll << j) + 1][j]);

        return u > v;
    };

    vector len(n + 1, vector<int>(mx_log));
    vector<int> pos(n + 1);

    auto initLen = [&]()
    {
        for (int j = 1; j < mx_log; j++)        
        {
            for (int i = 1; i + (1ll << j) - 1 <= n; i++)
            {
                len[i][j] = max(len[i][j - 1], len[i + (1ll << (j - 1))][j - 1]);
            }
        }
    };

    auto queryLen = [&](int l, int r)
    {
        int j = log_table[r - l + 1];
        return max(len[l][j], len[r - (1ll << j) + 1][j]);
    };

    auto sol1 = [&]()
    {
        for (int i = 1, j = 1; i <= n; i++)
        {
            while (j <= i && !query(j, i))
                j++;
    
            pos[i] = j;
            len[i][0] = i - j + 1;
        }   
    };

    auto sol2 = [&]()
    {
        for (int i = 1; i <= q; i++)
        {
            auto [l, r] = que[i];
            auto it = lower_bound(pos.begin() + l, pos.begin() + r + 1, l) - pos.begin();
            ans[i] = max(ans[i], (int)(it - l));
            if (it <= r)
                ans[i] = max(ans[i], queryLen(it, r));
        }
    };

    initST();
    sol1();
    initLen();
    sol2();

    for (int i = 1; i <= n; i++)
        h[i] = -h[i];

    initST();
    sol1();
    initLen();
    sol2();

    int res = 0;
    for (int i = 1; i <= q; i++)
        res = (res + ans[i] * i) % mod;
    cout << res;
}

signed main()
{
    ios::sync_with_stdio(false);
    cout.tie(nullptr);
    cin.tie(nullptr);
    int T = 1;
    cin >> T;
    while (T--)
        solve();
    return 0;
}
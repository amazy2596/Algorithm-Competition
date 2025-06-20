#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> e(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> e[i];
    
    auto check = [&](int x) -> int
    {
        int res = 0;
        for (int i = 1; i <= n; i++)
        {
            int num = (x + e[i]) / (2 * e[i]);
            int cost = e[i] * num * num;
            if (num > 1e9)
                return INT64_MAX;
            if (res + cost > m || cost < 0)
                return INT64_MAX;

            res += num * num * e[i];
        }

        return res;
    };

    int l = 1, r = m;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        if (check(mid) <= m)
            l = mid;
        else
            r = mid - 1;
    }

    int ans = 0;
    vector<int> nxt(n + 1);
    for (int i = 1; i <= n; i++)
    {
        int num = (l + e[i]) / (2 * e[i]);
        ans += num;
        nxt[i] = (2 * num + 1) * e[i];
        m -= e[i] * num * num;
    }

    ranges::sort(nxt);
    for (int i = 1; i <= n; i++)
    {
        if (m < nxt[i])
            break;
        m -= nxt[i];
        ans++;
    }

    cout << ans << "\n";
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
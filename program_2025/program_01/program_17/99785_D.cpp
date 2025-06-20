#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

struct pig
{
    int start, end;
    int b, val;

    bool operator<(const pig &other) const
    {
        return end < other.end;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<pig> pigs(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> pigs[i].start;
    for (int i = 1; i <= n; i++)
    {
        cin >> pigs[i].b >> pigs[i].val;
        pigs[i].end = pigs[i].start + m - 1;
    }

    sort(pigs.begin() + 1, pigs.end());

    vector<int> dp(n + 1, INT64_MAX);
    dp[0] = 0;

    auto find = [&](int idx)
    {
        int l = 1, r = idx - 1;
        int result = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2; 
            if (pigs[mid].end < pigs[idx].start)
            {
                result = mid;
                l = mid + 1;
            }
            else 
                r = mid - 1;
        }

        return result;
    };

    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++)
        pre[i] = pre[i - 1] + pigs[i].val;

    for (int i = 1; i <= n; i++)
    {
        dp[i] = min({dp[i], pre[i], dp[i - 1] + pigs[i].val});
        int lastValue = find(i);
        int cost = pigs[i].b;
        if (lastValue >= 0)
            dp[i] = min(dp[i], dp[lastValue] + pre[i - 1] - pre[lastValue] + cost);
        else 
            dp[i] = min(dp[i], pre[i - 1] + cost);
    }

    cout << dp[n] << "\n";
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
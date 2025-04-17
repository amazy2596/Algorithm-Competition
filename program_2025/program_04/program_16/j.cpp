#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int fast_pow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;

        b >>= 1;
        a = (a * a) % mod;
    }

    return res;
}

void solve()
{
    int m;
    cin >> m;
    int k = m;
    vector<int> a(10);
    int beg = -1;
    for (int i = 0; i <= 9; i++)
    {
        cin >> a[i];
        if (beg == -1 && i != 0 && a[i] != 0)
        {
            beg = i;
            a[i]--;
        }
    }

    if (m == 1 && a[0] != 0)
    {
        cout << "0\n";
        return;
    }

    vector<int> dp(64);
    auto pre = [&](int x)
    {
        dp[0] = x;
        for (int i = 1; i <= 63; i++)
            dp[i] = (dp[i - 1] * fast_pow(10, fast_pow(2, i - 1)) % mod + dp[i - 1]) % mod;
    };

    m--;
    vector<int> use(10, 0), after(10, 0);
    for (int i = 0; i <= 9; i++)
    {
        use[i] = min(m, a[i]);
        m -= min(m, a[i]);
    }
    
    for (int i = 8; i >= 0; i--)
        after[i] = after[i + 1] + use[i + 1];

    auto calc = [&](int a, int b)
    {
        int res = 0;
        int cnt = 0;
        int idx = 0;
        while (a)
        {
            if (a & 1)
            {
                res = (res + dp[idx] * fast_pow(10, cnt)) % mod;
                cnt += fast_pow(2, idx);
            }
            idx++;
            a >>= 1;
        }

        return res % mod * fast_pow(10, b) % mod % mod;
    };

    int ans = 0;
    pre(beg);
    ans += calc(1, k - 1);

    for (int i = 1; i <= 9; i++)
    {
        if (use[i] > 0)
        {
            pre(i);
            ans = (ans + calc(use[i], after[i])) % mod;
        }
    }

    cout << ans % mod << "\n";
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
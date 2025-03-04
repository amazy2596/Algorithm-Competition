#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

void solve()
{
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], pre[i] = pre[i - 1] ^ a[i];

    auto calc = [&](auto calc, int k) -> int
    {
        int res = 0;
        int nxt = k / 2;
        if (k <= n)
            return a[k];
        if (nxt <= n)
            return pre[nxt];
        if (nxt % 2 == 1)
        {
            if (n % 2 == 1)
                res = pre[n];
            else 
                res = pre[(n + 1) / 2] ^ pre[n];
        }
        else 
        {
            res ^= calc(calc, nxt);
            res ^= pre[n];
            if (n % 2 == 0)
                res ^= pre[(n + 1) / 2];
        }
        return res;
    };

    for (int i = 1; i <= r; i++)
        cout << calc(calc, i) << " ";
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
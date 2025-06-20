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
    int n;
    cin >> n;
    int ans1 = 1, ans2 = 1;
    for (int i = 0; i < n; i++)
    {
        int op, x;
        cin >> op >> x;
        x %= mod;
        if (op == 0)
            ans1 = (ans1 * (x % mod)) % mod;
        else 
            ans1 = (ans1 % mod * fast_pow(x, mod - 2)) % mod;
    }
    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int op, x;
        cin >> op >> x;
        x %= mod;
        if (op == 0)
            ans2 = (ans2 * (x % mod)) % mod;
        else
            ans2 = (ans2 % mod * fast_pow(x, mod - 2)) % mod;
    }

    cout << (ans1 % mod == ans2 % mod ? "YES\n" : "NO\n");
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
#include <bits/stdc++.h>
#define int long long
using namespace std;

const int mod = 1e9 + 7;
int n;

int fast_pow(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1)
            res = (res * a) % mod;
        b >>= 1;
        a = a % mod * a % mod;
    }
    return res;
}

void solve()
{
    cin >> n;
    vector<int> a(n + 1), pre(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        pre[i] = pre[i - 1] + a[i];
    }
    int x = 0;
    for (int i = n; i >= 1; i--)
    {
        x += a[i] * (pre[i - 1] % mod);
        x %= mod;
    }
    x %= mod;
    int y = (n - 1) * n / 2 % mod;
    cout << x * fast_pow(y, mod - 2) % mod << "\n";
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
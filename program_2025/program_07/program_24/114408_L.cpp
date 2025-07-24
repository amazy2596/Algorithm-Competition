#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int mod = 1e9 + 7;
int fast_pow(int a, int b) 
{
    int res = 1;
    a %= mod;
    while (b) 
    {
        if (b & 1)
            res = (res * a) % mod;

        a = (a * a) % mod;
        b >>= 1;
    }
    return res;
}

int inv(int x) 
{
    return fast_pow(x, mod - 2);
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), b(n + 1), c(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    for (int i = 1; i <= n; i++)
        cin >> c[i];

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = (ans + c[i] * (i * (i + 1) / 2)) % mod;

    vector<int> suf1(n + 2);
    for (int k = n; k >= 1; k--)
        suf1[k] = (suf1[k + 1] + n / k) % mod;

    vector<int> suf2(n + 2);
    for (int j = n; j >= 1; j--)
    {
        // suf2[j] = (suf2[j + 1] + ((n / j * suf1[j]) % mod * inv(b[j])) % mod) % mod;
        int tmp = (n / j) % mod;
        tmp = (tmp * suf1[j]) % mod;
        tmp = (tmp * inv(b[j])) % mod;
        suf2[j] = (suf2[j + 1] + tmp) % mod;
    }

    vector<int> pre(n + 2);
    for (int i = 1; i <= n; i++)
    {
        // pre[i] = (pre[i - 1] + ((a[i] % mod * n / i) % mod * suf2[i]) % mod) % mod;
        int tmp = (n / i) % mod;
        tmp = (tmp * a[i]) % mod;
        tmp = (tmp * suf2[i]) % mod;
        pre[i] = (pre[i - 1] + tmp) % mod;
    }

    ans = (ans + pre[n]) % mod;
    cout << ans % mod << "\n";
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
#include <bits/stdc++.h>
#define uint uint64_t
#define int long long
using namespace std;

const double eps = 1e-12;
const int inf = 1e18;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](uint l, uint r) { return (l <= r ? uniform_int_distribution<uint>(l, r)(rng) : 0); };

const int mod1 = 1000000007;
const int mod2 = 998244353;
const int mod = mod1;
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
    int x, p, q, m;
    cin >> x >> p >> q >> m;

    int l = ((q - p + mod) * inv(q)) % mod;
    int r = (p * inv(q)) % mod;

    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i] >> b[i];

    int ans = 0;
    map<int, int> mp;
    for (int t = 0; t < (1ll << n); t++)
    {
        int fee = 0, stone = 0;
        for (int k = 0; k < n; k++)
        {
            if ((t >> k) & 1)
            {
                fee += a[k];
                stone += b[k];
            }
        }
        int cnt = min(m, stone / x);
        for (int j = cnt; j > 0; j--)
        {
            if (mp.find(j) != mp.end())
                mp[j] = min(mp[j], fee);
            else
                mp[j] = fee;
        }
    }
    for (auto [cnt, fee] : mp)
    {
        int tmp = 0;
        if (cnt == m)
            tmp = (tmp + fast_pow(l, cnt - 1)) % mod;
        else 
            tmp = (tmp + fast_pow(l, cnt - 1) * r) % mod;

        ans = (ans + tmp * fee) % mod;
    }

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
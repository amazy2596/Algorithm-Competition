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
const int mod = mod2;
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

struct node
{
    int l, r, p, q;

    bool operator<(node o)
    {
        auto a = make_pair(l, r);
        auto b = make_pair(o.l, o.r);

        return a < b;
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<node> a(n);
    for (auto &[l, r, p, q] : a)
        cin >> l >> r >> p >> q;

    sort(a.begin(), a.end());
    a.insert(a.begin(), node(0, 0, 0, 1));
    vector<int> pre(n + 1);
    pre[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        auto [l, r, p, q] = a[i];
        int tmp = ((q - p) * inv(q)) % mod;
        pre[i] = (pre[i - 1] * tmp) % mod;
    }

    vector<int> dp(m + 1);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        auto [l, r, p, q] = a[i];
        int w = (p * inv(q - p)) % mod;
        dp[r] = (dp[r] + dp[l - 1] * w) % mod;
    }

    cout << (dp[m] * pre[n]) % mod << "\n";
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
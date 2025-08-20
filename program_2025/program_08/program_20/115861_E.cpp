// Problem: 小苯的xor图
// URL: https://ac.nowcoder.com/acm/contest/115861/E
// Author: amazy
// Date: 2025-08-20 23:13:39

#include <bits/stdc++.h>
using namespace std;
using i64 = int64_t;
using u64 = uint64_t;
using f64 = long double;
using i128 = __int128_t;
using u128 = __uint128_t;

const long double eps = 1e-12;
const i64 mod = 998244353;
const i64 INF = 1e18;
const int inf = 1e9;

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());
auto rnd = [](i64 l, i64 r) { return (l <= r ? uniform_int_distribution<i64>(l, r)(rng) : 0); };

i64 fast_pow(i64 a, i64 b) 
{
    i64 res = 1;
    a %= mod;
    while (b) 
    {
        if (b & 1)
            res = (1LL * res * a) % mod;

        a = (1LL * a * a) % mod;
        b >>= 1;
    }
    return res;
}

i64 inv(i64 x) 
{
    return fast_pow(x, mod - 2);
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    i64 ans = 0;
    for (int u = 1; u <= n; u++)
    {
        vector<int> bits(32);
        for (int v : adj[u])
        {
            for (int k = 0; k < 31; k++)
                bits[k] += (a[v] >> k & 1);
        }

        int siz = adj[u].size() - 1;
        for (int v : adj[u])
        {
            int w = a[v] ^ a[u];
            for (int k = 0; k < 31; k++)
            {
                bits[k] -= (a[v] >> k & 1);
                if (w >> k & 1)
                    ans = (ans + (siz - bits[k]) * (1LL << k)) % mod;
                else 
                    ans = (ans + bits[k] * (1LL << k)) % mod;
                bits[k] += (a[v] >> k & 1);
            }
        }
    }

    ans = (ans * inv(2)) % mod;
    cout << ans << "\n";
}

int main()
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